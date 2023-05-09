#include "./PmergeMe.hpp"



int main (int argc , char *argv[])
{

    std::vector <int> vec;
    std::list <int> lis;
    std::string input  = joinArray (argv);

    try
    {
         vec = getVector (input);
         lis = getList (input);
            std::cout << "vector : " ;
            printContainer(vec);
            std::cout << "list : ";
            printContainer (lis);
        /* code */
    }
    catch(const std::exception& e)
    {

        std::cerr << e.what() << '\n';
    }
    
    return (0);
}