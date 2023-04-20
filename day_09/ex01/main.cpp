#include "./RPN.hpp"



int main (int argc ,char *argv [])
{
    std::stack <std::string> rpnStack;
    if (argc != 2)
    {
        std::cout << "Invalid number of arguments !" << std::endl;
        exit (EXIT_FAILURE);
    }
    try
    {
        rpnStack = getStack (argv[1]);    
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        exit (EXIT_FAILURE);
    }
    

    std::cout <<"\e[0;31m" << RPN (rpnStack) <<"\e[0m"  <<  std::endl; 
    
    return (0);
}