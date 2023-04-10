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