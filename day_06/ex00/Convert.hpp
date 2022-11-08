#ifndef CONVERT_HPP_
#define CONVERT_HPP_

#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>
#include <limits>

enum types {CHAR,INT, FLOAT, DOUBLE, PSEUDO, INVALID};

int		validateFloat (std::string arg, int flag);
int		validateSign (std::string arg, char c);
int		getType (std::string arg);
void	handleInt(std::string arg);
void	handlChar (std::string arg);
void	handleFloat (std::string arg);
void	handleDouble(std::string arg);
int		countPrecision(std::string arg);
void	handlePseudo (std::string arg);

#endif
