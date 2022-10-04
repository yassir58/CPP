#include "Harl.hpp"




int main ()
{
	Harl karen;

	std::cout << "[DEBUG] : ";
	karen.complain("debug"); 
	std::cout << std::endl;
	std::cout << "[INFO] : ";
	karen.complain("info"); 
	std::cout << std::endl;
	std::cout << "[WARNING] : ";
	karen.complain("warning"); 
	std::cout << std::endl;
	std::cout << "[ERROR] : ";
	karen.complain("error"); 
	std::cout << std::endl;
	std::cout << "[UNDEFINED] : ";
	karen.complain("undefined"); 
	std::cout << std::endl;
	karen.complain("hahahah"); 
	std::cout << std::endl;
	
	return (0);
}