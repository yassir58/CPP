#ifndef PMERGE_ME_HPP_
#define PMERGE_ME_HPP


#include <iostream>
#include <vector>
#include <deque>
#include <sstream>
#include <algorithm>
#include <iterator>
#include <ctime>
#include <iomanip>

class Error : public std::exception {
    
    private:
        const char *err_description ;
    public:
        virtual const char *what(void) const throw();
        Error (const char *error);
};


void printContainer(std::vector <int> vect);
void printContainer(std::deque <int> deq);
std::vector <int> getVector (std::string input);
std::string joinArray (char *argv[]);
std::deque <int> getDeque (std::string input);
std::vector<int> partition(std::vector<int> list, int start,int end);
void mergeSort (std::deque <int> deq, int len, std::deque <int> &tmp);
void mergeSort (std::vector <int> list, int len, std::vector<int> &tmp);
void sort (std::vector<int> &vect);
void sort (std::deque<int> &deq);

#endif