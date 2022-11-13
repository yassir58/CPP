#include "Convert.hpp"


int main (int argc, char *argv[])
{
	int precision = 0;
	// float fmax  = std::numeric_limits<float>::max ();
	// double test = static_cast<double>(fmax);

	// std::cout << std::fixed ;
	// std::cout << fmax << std::endl;
	// std::cout << test << std::endl;
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
			precision = countPrecision (argv[1]);
			std::cout.precision (precision);
			std::cout << std::fixed ;
			std::cout << "type : " << getType (argv[1]) << std::endl;
			if (getType (argv[1]) == INT)
				handleInt (argv[1]);
			else if (getType (argv[1]) == DOUBLE)
				handleDouble (argv[1]);
			else if (getType (argv[1]) == FLOAT)
				handleFloat (argv[1]);
			else if (getType (argv[1]) == PSEUDO)
				handlePseudo (argv[1]);
			else
				handleChar (argv[1]);
		}
	}
	return (0);
}
