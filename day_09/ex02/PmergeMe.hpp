#ifndef PMERGE_ME_HPP_
#define PMERGE_ME_HPP


#include <iostream>
#include <vector>
#include <list>
#include <sstream>



class Error : public std::exception {
    
    private:
        const char *err_description ;
    public:
        virtual const char *what(void) const throw();
        Error (const char *error);
};


void printContainer(std::vector <int> vect);
void printContainer(std::list <int> list);
std::vector <int> getVector (std::string input);
std::string joinArray (char *argv[]);
std::list <int> getList (std::string input);

#endif