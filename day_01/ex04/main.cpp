#include "replace.hpp"

int main (int argc, char *argv[])
{
	std::fstream out_file;
	std::string content;

	if (argc != 4)
	{
		std::cout<<"Invalid number of arguments !"<<std::endl;
		return (1);
	}
	content = getFileContent (argv[1]);
	if (!content.compare (""))
	{
		std::cout << "empty file"<< std::endl;
		return (1);
	}
	out_file.open ("outfile", std::ios::out);
	if (out_file.fail())
	{
		std::cout << "failed to open file for writing;"<<std::endl;
		return (1);
	}
	out_file << replace (content, argv[2], argv[3]);;
	out_file.close ();
}