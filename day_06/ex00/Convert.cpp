#include "Convert.hpp"

int main (int argc, char *argv[])
{
	if (argc == 1)
		std::cerr << "Error: Inavlid arguments !" << std::endl;
	else
	{
		if (getType(argv[1]) == INVALID)
		{
			std::cout << " << Invalid literal >> " << std::endl;
			return (0);
		}
		else
		{
			std::cout.precision (1);
			std::cout << std::fixed ;
			handlChar(argv[1]);
			handleInt (argv[1]);
			handleFloat (argv[1]);
			handleDouble (argv[1]);
		}
	}
	return (0);
}