#include "./PmergeMe.hpp"


Error::Error (const char *error)
{
    err_description = error;
}

const char *Error::what (void) const throw()
{
    return (this->err_description);
}

int toInt (std::string str)
{
    int res;
    std::stringstream ss(str);
    ss >> res;
    return (res);
}

std::string toString (int number)
{
    std::stringstream ss;
    std::string str;
    ss << number;
    ss >> str;
    return (str);
}

void validateInput (std::string input)
{
    if (input.find_first_not_of ("0123456789") != std::string::npos)
        throw Error ("Error!");
}


std::vector <int> getVector (std::string input)
{
    std::stringstream ss(input);
    int num ;
    std::string word;
    std::vector <int> vector;


    while (ss >> word)
    {
        validateInput (word);
        num = toInt(word);
        vector.push_back (num);
    }
    return (vector);
}

std::list <int> getList (std::string input)
{
    std::stringstream ss(input);
    int num ;
    std::string word;
    std::list <int> list;


    while (ss >> word)
    {
        validateInput (word);
        num = toInt(word);
        list.push_back (num);
    }
    return (list);
}

std::string joinArray (char *argv[])
{
    std::string str("");
    int i = 1;

    while (argv[i])
    {
        str.append (argv[i]);
        i++;
    }
    return (str);
}


void printContainer(std::vector <int> vect)
{
    for  (std::vector<int>::iterator it = vect.begin(); it != vect.end (); ++it)
        std::cout << (*it) << " " ;
    std::cout << std::endl;
}

void printContainer(std::list <int> list)
{
    for  (std::list<int>::iterator it = list.begin(); it != list.end (); ++it)
        std::cout << (*it) << " " ;
    std::cout << std::endl;
}

