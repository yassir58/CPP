#include "./PmergeMe.hpp"



int main (int argc , char *argv[])
{

    std::vector <int> vec;
    std::deque <int> deq;
    
    if (argc == 1)
    {
        std::cerr << "Invalid number of arguments !" << std::endl;
        exit (EXIT_FAILURE);
    }
    std::string input  = joinArray (argv);
    try
    {
        vec = getVector (input);
        std::cout << "before : ";
        printContainer (vec);
        deq = getDeque (input);
        sort (vec);
        sort (deq);
        /* code */
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    return (0);
}