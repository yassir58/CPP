#ifndef _REPLACE_HPP
#define _REPLACE_HPP


#include <iostream>
#include <string>
#include <fstream>

std::string getFileContent (std::string file_name);
std::string replace (std::string str, std::string pattern, std::string rep);
#endif