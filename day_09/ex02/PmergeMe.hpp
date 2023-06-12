#ifndef PMERGE_ME_HPP_
#define PMERGE_ME_HPP


#include <iostream>
#include <vector>
#include <list>
#include <sstream>
#include <algorithm>
#include <iterator>
#include <ctime>

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
std::vector<int> partition(std::vector<int> list, int start,int end);
void mergeSort (std::vector <int> list, int len, std::vector<int> &tmp);


#endif