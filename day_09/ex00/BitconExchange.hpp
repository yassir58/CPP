#ifndef _BITCOIN_EXCHANGE_
#define _BITCOIN_RXCHANE_

#include <iostream>
#include <fstream>
#include <map>
#include <sstream>
#include <iomanip>
#include <string.h>
#include <algorithm>

class InputError : public std::exception {
     const char *err_description ;
     const char *context;
    public:
        virtual const char *what(void) const throw();
        InputError (const char* desc,  const char *context);
};

int validateDate (std::string date);
std::string  getClosestDate (std::string target, std::map <std::string, double>  data);



#endif