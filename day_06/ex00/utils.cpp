#include "Convert.hpp"

int validateFloat (std::string arg, int flag)
{
	int count = 0 ;
	size_t i;

	if (flag == FLOAT )
	{
		for (i = 0; (i = arg.find('f', i)) != std::string::npos; i++)
			count++;
		if (count > 1 || arg.back () != 'f')
			return (0);
		count = 0;
	}
	for (i = 0; (i = arg.find('.', i)) != std::string::npos; i++)
		count++;
	i = arg.find('.');
	if (arg[0] == '.' || count != 1 || (arg[i + 1] == 'f') || arg.back () == '.')
		return (0);
	return (1);
}

int validateSign (std::string arg, char c)
{
	int count = 0;

	for (size_t i = 0; (i = arg.find (c, i)) != std::string::npos; i++)
		count++;
	if (count > 1)
		return (0);
	if (count == 1 && arg.find (c, 0) != 0)
		return (0);
	return (1);
}

int getType (std::string arg)
{
	int flag = INVALID;

	if (!arg.compare("-inf") || !arg.compare("+inf") || !arg.compare("nan") 
		|| !arg.compare("-inff") || !arg.compare("+inff") || !arg.compare("nanf"))
		flag = PSEUDO;
	else if (arg.find_first_not_of("+-0123456789") == std::string::npos)
		flag = INT;
	else if (arg.find_first_not_of("+-0123456789.f") == std::string::npos)
	{
		if (arg.find(".") != std::string::npos)
		{
			if (arg.find("f") != std::string::npos)
				flag = FLOAT;
			else
				flag = DOUBLE;
		}
	}
	if (!validateSign(arg, '-') || !validateSign(arg, '+'))
		flag = INVALID;
	if (flag == FLOAT)
	{
		if (!validateFloat(arg, FLOAT))
			return (INVALID);
	}
	if (flag == DOUBLE)
	{
		if (!validateFloat(arg, DOUBLE))
			return (INVALID);
	}
	return (flag);
}


void  handleInt(std::string arg)
{
	int iValue;

	try
	{
		iValue = std::stoi(arg);
	}
	catch(const std::exception& e)
	{
		std::cerr << "int: impossible" << '\n';
		return;
	}
	std::cout << "int: " << iValue << std::endl;
}

void handlChar (std::string arg)
{
	char cValue;
	int iValue;

	
	try
	{
		iValue = std::stoi(arg);
	}
	catch(const std::exception& e)
	{
		std::cerr << "char: impossible" << '\n';
		return;
	}
	if (iValue > 32 && iValue < 127)
	{
		cValue = iValue;
		std::cout << "char: '" << cValue << "'" << std::endl;
	}
	else
		std::cout << "char: Non displayable" << std::endl;
}


void handleFloat (std::string arg)
{
	float fValue = 0;

	if (getType (arg) == PSEUDO)
	{
			std::string a = std::to_string(std::stof(arg));
			std::cout <<"float: " << a.append("f") << std::endl;
			return ;	
	}
	try
	{
		fValue = std::stof(arg);
	}
	catch(const std::exception& e)
	{
		std::cerr << "float: impossible" << '\n';
		return;
	}
	
	std::cout << "float: " << fValue ;
	if (getType (arg) == FLOAT || getType (arg) == DOUBLE)
	{
		std::cout << "f";
	}
	else if (getType (arg) == INT)
		std::cout << ".0f";
	std::cout << std::endl;
}

void handleDouble(std::string arg)
{
	double dValue;

	try
	{
		dValue = std::stod(arg);
	}
	catch(const std::exception& e)
	{
		std::cerr << "double: impossible" << '\n';
		return;
	}
	std::cout << "double: " << dValue ;
	if (getType (arg) == INT)
		std::cout << ".0";
	std::cout << std::endl;
}