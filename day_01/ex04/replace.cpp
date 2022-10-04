#include "replace.hpp"


std::string getFileContent (char *file_name)
{
	std::string str = "";
	std::string line;
	std::fstream in_file;

	in_file.open(file_name, std::ios::in);
	if (!in_file)
	{
		std::cout << "file doesn't exist !"<<std::endl;
		exit (EXIT_FAILURE);
	}
	while (!in_file.eof())
	{
		getline (in_file, line);
		str.append (line + "\n");
	}
	in_file.close ();
	return (str);
}


std::string replace (std::string str, std::string pattern, std::string rep)
{
	size_t indx = 0;
	size_t start = 0;
	while (true)
	{
		indx = str.find(pattern, start);
		if (indx == std::string::npos)
			break;
		else
			start = indx + rep.length();
		str = str.substr(0, indx) + rep + str.substr(indx + pattern.length(), str.length() - (indx + pattern.length()));
	}
	return (str);
}
