#include "BitconExchange.hpp"


InputError::InputError (char const *desc, char const *context)
{
    this->err_description = desc;
    this->context = context;
}

 const char *InputError::what (void) const throw ()
{
    return (err_description);
}


int validateDate (std::string date)
{
    std::stringstream tmp (date);
    char delim  = '-';
    int count  = 0;
    std::string value;
    double numValue;

    if (date.find_first_not_of ("-0123456789 ") != std::string::npos)
        throw InputError ("bad input => ", date.c_str());
    while (std::getline (tmp, value, delim))
    {
        if (value.find_first_not_of (" \n") == std::string::npos)
            throw InputError ("bad input ", "invalid date");
        std::stringstream tmepValue (value);
        tmepValue >> numValue ;
        if (count == 0 && numValue < 0)
            throw InputError ("bad input ", "out of range");
        else if (count == 1 && (numValue < 0 || numValue > 12))
            throw InputError ("bad input ", "out of range");
        else if (count == 2)
        {
            delim = '\n';
            if ((numValue < 0 || numValue > 31))
                throw InputError ("bad input ", "out of range");
        }
        count++;
    }
    return (0);
}

std::string  getClosestDate (std::string target, std::map <std::string, double>  data)
{
    struct tm targetDate = {0};
    time_t temp;
    std::string targetKey;
    std::map <std::string , double> ::iterator it;
    strptime(target.c_str(), "%Y-%m-%d", &targetDate);
    time_t targetTimestamp = mktime(&targetDate);
    temp = targetTimestamp;

    it = data.lower_bound (target);
    // std::cout << "lower bound " << (*it).first << std::endl;
    while (it != data.begin())
    {
        strptime ((*it).first.c_str(), "%Y-%m-%d", &targetDate);
        targetTimestamp = mktime (&targetDate);
        if (targetTimestamp < temp)
        {
            targetKey = (*it).first;
            return targetKey;
        }
        it--;
    }
    return (targetKey);
}


std::map<std::string , double> getDatabase(std::ifstream &file)
{
    int index  = 0;
    char delim = ',' ;
    std::map <std::string , double> database;
    double value;
    std::string key;
    std::string line ;

    while (std::getline (file , line, delim))
    {
       if (index % 2 == 0)
       {
            delim = '\n';
            key = line ;
       }
       else 
        {
            delim = ',';
            std::istringstream str (line);            
            str >> value;
            database[key] = value;
        }
        index++;
    }
    return (database);
}


void printResult (std::string date, double price, std::map<std::string , double> database)
{
    std::string targetDate;
    double targetPrice;

    
    std::string::size_type pos  = date.find_last_not_of (' ');
    if (pos != std::string::npos)
        date.erase (pos + 1);
    // std::cout << "date " << date << std::endl ;
    if (database.find (date) == database.end ())
    {
        targetDate = getClosestDate (date, database);
        targetPrice = database[targetDate];
        // std::cout << "\e[0;31m closest date " << targetDate << "\e[0m" << std::endl ;
    }
    else
    {
        targetDate = date;
        targetPrice = database[targetDate];
    }
    std::cout << targetDate << " " << price << " "  << targetPrice << " => " <<  price * targetPrice << std::endl; 

}

void processTransactrion (std::ifstream &inputFile, std::map <std::string, double> database)
{
    int count  = 2;
    std::string line;
    std::string key, value;
    double price;

    while (std::getline (inputFile, line))
    {

        price = 0;
        std::stringstream tmp (line);
        key = "", value = "";
        std::getline (tmp , key, '|');
        std::getline (tmp, value);
        std::stringstream tmpNum(value);
        try {
            tmpNum >> price ;
            validateDate (key);
            std::cout << "price : " << price << std::endl;
            if (price < 0)
                throw InputError ("not a positive number", "");
            else if (price > 1000)
                throw InputError ("to large number", "");
            printResult (key, price, database); 
        }
        catch (std::exception &exc)
        {
            std::cout << "Error: " << exc.what ()  << std::endl;
        }

    }
}
