#include "Harl.hpp"




int main (int argc , char *argv[])
{
	Harl karen;

	if (argc < 2)
		return (1);
	karen.complain (argv[1]);
	return (0);
}