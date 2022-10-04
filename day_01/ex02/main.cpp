#include "iostream"



int  main (void)
{
	std::string str("HI THIS IS BRAIN");
	std::string *stringPTR;
	std::string &stringREF = str;

	stringPTR = &str;
	std::cout<<"this is ptr : "<<*stringPTR<<std::endl;
	std::cout<<"this is ref : "<<stringREF<<std::endl;
	std::cout<<"this is ptr address: "<<stringPTR<<std::endl;
	std::cout<<"this is ref address: "<<&stringREF<<std::endl;
	return (0);
}