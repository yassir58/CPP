#ifndef RPN_HPP_
#define RBN_HPP_


#include <iostream>
#include <stack>
#include <sstream>


class Error : public std::exception {
    
    private:
        const char *err_description ;
    public:
        virtual const char *what(void) const throw();
        Error (const char *error);
};

std::stack<std::string> getStack (std::string input);
void validateInput (std::string input);
int RPN(std::stack <std::string>);

#endif 