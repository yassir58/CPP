#include "replace.hpp"


std::string getFileContent (std::string file_name)
{
	std::string str = "";
	std::string line;
	std::fstream in_file;
	int flag = 0;

	in_file.open(file_name, std::ios::in);
	if (!in_file)
	{
		std::cout << "failed to open file for reading!"<<std::endl;
		exit (EXIT_FAILURE);
	}
	while (!in_file.eof())
	{
		getline (in_file, line);
		if (line.compare (""))
			flag++;
		str.append (line + "\n");
	}
	in_file.close ();
	if (flag == 0)
		return ("");
	return (str);
}

std::string replace (std::string str, std::string pattern, std::string rep)
{
	size_t indx = 0;
	size_t start = 0;
	while (true && pattern.compare(""))
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
