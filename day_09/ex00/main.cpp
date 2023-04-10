#include "BitconExchange.hpp"



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
    // double result  = 0;
    // std::map <std::string , double>::iterator it;
    // std::cout << date << " => " << price << " = " << result << std::endl;
  
    // if (database.find (date) == database.end ())
    // {
    //     std::cout << "value does not exists" << std::endl;
    //     it = database.lower_bound (date);
    //     if (it  == database.end ())
    //         std::cout << "no lower bound found " << std::endl;
    //     else
    //         std::cout << "\e[0;32m lower bound found " << (*it).first << "\e[0m" << std::endl;
    // }
    // else    
    //     std::cout << "\e[0;31m date found " << date << "\e[0m" << std::endl;
   
}

void processTransactrion (std::ifstream &inputFile, std::map <std::string, double> database)
{
    int count  = 2;
    std::string line;
    std::string key, value;
    double price;

    while (std::getline (inputFile, line))
    {

        std::stringstream tmp (line);
        key = "", value = "";
        std::getline (tmp , key, '|');
        std::getline (tmp, value);
        std::stringstream tmpNum(value);
        try {
            tmpNum >> price ;
            validateDate (key);
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

int main(int argc, char *argv[])
{
    std::ifstream inputFile;
    std::string line;
    std::ifstream databaseInput ("data.csv");
    std::map <std::string, double> database;
    std::map <std::string, std::string> input;
    std::map<std::string , std::string>::iterator it; 

    if (argc != 2)
        return (std::cerr << "Invali number of arguments !" << std::endl, EXIT_FAILURE);
    inputFile.open (argv[1]);
    if (inputFile.is_open ())
    {
        database = getDatabase (databaseInput);
        try {
            processTransactrion (inputFile, database);
        }
        catch (std::exception &exc)
        {
            std::cout << exc.what () << std::endl;
            exit (EXIT_FAILURE);
        }
    }
    else
        return (std::cout << "Input file does not exist" << std::endl, EXIT_FAILURE);

    inputFile.close ();
    return (1);
}
