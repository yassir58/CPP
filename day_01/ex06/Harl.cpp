#include "Harl.hpp"


void Harl::debug (void)
{
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}

void Harl::info (void)
{
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!"<< std::endl;
}


void Harl::warning (void)
{
	std::cout<<"I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month."<<std::endl;
}

void Harl::error (void)
{
	std::cout<<"This is unacceptable! I want to speak to the manager now."<<std::endl;
}

void Harl::complain (std::string level)
{
	void (Harl:: *funcPtr[4])(void) ;
	std::string arr[4];
	int indx = 0;
	int count = 4;

	funcPtr[0] = &Harl::debug;
	funcPtr[1] = &Harl::info;
	funcPtr[2] = &Harl::warning;
	funcPtr[3]=  &Harl::error;
	arr[0] = "DEBUG";
	arr[1] = "INFO";
	arr[2] = "WARNING";
	arr[3] = "ERROR";

	while (level.compare(arr[indx]) && count--)
		indx++;
	switch (indx)
	{
		case 0:
		case 1:
		case 2:
		case 3:	
			while (indx < 4)
			{
				std::cout << "[ " << arr[indx].c_str() << " ]" << std::endl;
				(this->*funcPtr[indx])();
				indx++;
			}
		break;
	default:
		std::cout<<"[ Probably complaining about insignificant problems ]"<<std::endl;
		break;
	}
}