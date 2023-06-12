#include "./PmergeMe.hpp"



int main (int argc , char *argv[])
{

    std::vector <int> vec;
    std::list <int> lis;
    std::vector<int> tmp;
    std::string input  = joinArray (argv);

    try
    {
        std::cout << "input : " << input << std::endl;
        vec = getVector (input);
        lis = getList (input);

         // Start the clock
        clock_t startTime = clock();
        mergeSort (vec,vec.size() , tmp);
        // Stop the clock
        clock_t endTime = clock();

        // Calculate the duration
        clock_t duration = endTime - startTime;

        // Print the execution time in seconds
        std::cout << "Execution time: " << static_cast<double>(duration) / CLOCKS_PER_SEC << " seconds" << std::endl;

        /* code */
    }
    catch(const std::exception& e)
    {

        std::cerr << e.what() << '\n';
    }
    
    return (0);
}