#include "Convert.hpp"


int checkOverflow (std::string arg, int flag)
{
	double test;
	std::stringstream s;
	int imax = std::numeric_limits<int>::max ();
	int cmax = std::numeric_limits<char>::max ();
	float fmax  = std::numeric_limits<float>::max ();

	s << arg;
	s >> test;
	if (flag == INT)
	{
		if (test > imax)
			return (0);
	}
	if (flag == CHAR)
	{
		if (test > cmax)
			return (0);
	}
	if (flag == FLOAT)
	{
		if (test > fmax)
			return (0);
	}
	return (1);
}

int checkUnderflow (std::string arg, int flag)
{
	double test;
	std::stringstream s;
	int imin = std::numeric_limits<int>::min ();
	int cmin = std::numeric_limits<char>::min ();
	float fmin  = std::numeric_limits<float>::min ();

	s << arg;
	s >> test;
	if (flag == INT)
	{
		if (test < imin)
			return (0);
	}
	if (flag == CHAR)
	{
		if (test < cmin)
			return (0);
	}
	if (flag == FLOAT)
	{
		if (test < fmin)
			return (0);
	}
	return (1);
}

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
	if (flag == INT)
	{
		if (!checkOverflow (arg, INT) || !checkUnderflow (arg, INT))	
			flag = DOUBLE;
	}
	return (flag);
}

void handleInt (std::string arg)
{
	char cValue;
	int iValue;
	float fValue;
	double dValue;
	std::stringstream s;

	s << arg;
	s >> iValue;
	if (!checkOverflow(arg, CHAR) || !!checkUnderflow(arg, CHAR))
		std::cout << "char : impossible " << std::endl;
	else
	{
		cValue = static_cast<char>(iValue);
		if (cValue > 32 && cValue < 127)
			std::cout << "char : " << cValue << std::endl;
		else
			std::cout << "char : Non displayable " << std::endl;
	}
	if (!checkOverflow(arg, INT) || !checkUnderflow(arg, INT))
		std::cout << "int : impossible " << std::endl;
	else
		std::cout << "int : " << iValue << std::endl;
	fValue = static_cast<float>(iValue);
	std::cout << "float : " << fValue << std::endl;
	dValue = static_cast<double>(iValue);
	std::cout << "double : " << dValue << std::endl;
}

void handleDouble (std::string arg)
{
	char cValue;
	int iValue;
	float fValue;
	double dValue;
	std::stringstream s;

	s << arg;
	s >> dValue;
	if (!checkOverflow(arg, CHAR) || !checkUnderflow(arg, CHAR))
		std::cout << "char : impossible " << std::endl;
	else
	{
		cValue = static_cast<char>(dValue);
		if (cValue > 32 && cValue < 127)
			std::cout << "char : " << cValue << std::endl;
		else
			std::cout << "char : Non displayable " << std::endl;
	}
	if (!checkOverflow(arg, INT) || !checkUnderflow(arg, INT))
		std::cout << "int : impossible " << std::endl;
	else
	{
		iValue = static_cast <int> (dValue);
		std::cout << "int : " << iValue << std::endl;
	}
	
	if (!checkOverflow (arg, FLOAT) || !checkUnderflow(arg, CHAR))
		std::cout << "float : impossible " << std::endl;
	else
	{
		fValue = static_cast<float>(dValue);
		std::cout << "float : " << fValue << std::endl;
	}
	std::cout << "double : " << dValue << std::endl;
}

void handleFloat (std::string arg)
{
	char cValue;
	int iValue;
	float fValue;
	double dValue;
	std::stringstream s;

	s << arg;
	s >> fValue;
	if (!checkOverflow(arg, CHAR) || !checkUnderflow(arg, CHAR))
		std::cout << "char : impossible " << std::endl;
	else
	{
		cValue = static_cast<char>(fValue);
		if (cValue > 32 && cValue < 127)
			std::cout << "char : " << cValue << std::endl;
		else
			std::cout << "char : Non displayable " << std::endl;
	}
	if (!checkOverflow(arg, INT) || !checkUnderflow(arg, INT))
		std::cout << "int : impossible " << std::endl;
	else
	{
		iValue = static_cast<int>(fValue);
		std::cout << "int : " << iValue << std::endl;
	}
	if (!checkOverflow (arg, FLOAT) || !checkUnderflow(arg, FLOAT))
		std::cout << "float : impossible " << std::endl;
	else
	{
		fValue = static_cast<float>(fValue);
		std::cout << "float : " << fValue << std::endl;
	}
	dValue = static_cast<double>(fValue);
	std::cout << "double : " << dValue << std::endl;
}
