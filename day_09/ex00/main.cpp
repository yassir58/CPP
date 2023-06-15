#include "BitconExchange.hpp"




int main(int argc, char *argv[])
{
    std::ifstream inputFile;
    std::string line;
    std::ifstream databaseInput ("data.csv");
    std::map <std::string, double> database;
    std::map <std::string, std::string> input;
    std::map<std::string , std::string>::iterator it; 

    if (argc != 2)
        return (std::cerr << "Invali number of arguments !" << std::endl, EXIT_FAILURE);
    inputFile.open (argv[1]);
    if (inputFile.is_open ())
    {
        database = getDatabase (databaseInput);
        try {
            processTransactrion (inputFile, database);
        }
        catch (std::exception &exc)
        {
            std::cout << exc.what () << std::endl;
            exit (EXIT_FAILURE);
        }
    }
    else
        return (std::cout << "Input file does not exist" << std::endl, EXIT_FAILURE);

    inputFile.close ();
    return (1);
}
