#include "./RPN.hpp"



int main (int argc ,char *argv [])
{
    std::stack <std::string> rpnStack;
    if (argc != 2)
    {
        std::cout << "Invalid number of arguments !" << std::endl;
        return (1);
    }
    try
    {
        rpnStack = getStack (argv[1]);    
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        return (1);
    }
    

    std::cout <<"\e[0;31m" << RPN (rpnStack) <<"\e[0m"  <<  std::endl; 
    
    return (0);
}