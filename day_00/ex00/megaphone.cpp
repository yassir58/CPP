#include <iostream>




char *capitalize (char *str)
{
	int len;

	len = strlen (str);
	for (int i=0; i < len ;i++)
	{
		if (isalpha (str[i]))
			str[i] = toupper (str[i]);
	}
	return str;
}

int main (int argc, char *argv[])
{
	if (argc >= 2)
	{
		for (int i = 1; i < argc; i++)
			std::cout << capitalize (argv[i]);
		std::cout << std::endl;
	}
	else
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	return 0;
}