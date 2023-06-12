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
        str.append (argv[i]).append (" ");
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

std::vector<int> partition(std::vector<int> list, int start, int end)
{
    std::vector <int> newList;

    for (int i = start; i <= end ;i++)
    {
        newList.push_back (list[i]);
    }
    return newList;
}



int getPosition(const std::vector<int>& arr, int low, int high, int target) {
    while (low <= high) {
        int mid = low + (high - low) / 2;

 
        if (arr[mid] < target)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return low;
}


void insert(std::vector <int> &vector, std::vector <int> sub)
{

    int len = sub.size ();
    int pos = 0;
    std::vector <int>::iterator it;

    if (!vector.size ())
    {
        for (it=sub.begin(); it < sub.end (); it++)
            vector.push_back (*(it));
    }else
    {
        it = vector.end();
        for (int i = 0; i < len; i++)
        {
                int j = i - 1;
                pos = getPosition (vector, 0, vector.size () - 1, sub[i]);
                it = std::next(vector.begin (), pos);
                vector.insert (it, sub[i]);
        }
    }
}

void insert_(std::vector <int> &vector, std::vector <int> sub)
{
    int low  = 0;
    int high = vector.size () - 1;
    int mid = (low + high) /2;
    int len = sub.size ();
    std::vector <int>::iterator it;

    if (!vector.size ())
    {
        for (it=sub.begin(); it < sub.end (); it++)
        {
            vector.push_back (*(it));
        }
    }else
    {
        for (int i = 0; i < len; i++)
        {
            it = vector.begin ();
            while ((it) != vector.end() && (*it) < sub[i])
                it++;
            std::cout << "=> " << *it << std::endl;
            if (it == vector.end())
                vector.push_back(sub[i]);
            else
                vector.insert (it, sub[i]);
        }
    }
}

void mergeSort (std::vector <int> list, int len, std::vector <int> &tmp)
{

    std::vector <int> left;
    std::vector <int> right;
   
    int mid = 0;

    if (len <= 2)
    {
        if (len > 1)
        {
            if (list [0] > list[1])
                std::swap (list[0], list[1]);
        }
        // std::cout << "sorted subarray:\n";
        // printContainer (list);
        insert (tmp, list);
        std::cout << "=== > ";
        printContainer (tmp);
    }
    else
    {
        mid = len / 2;
        left   = partition (list,  0, mid -1);
        right  = partition (list, mid, len -1);
        mergeSort (left, left.size(), tmp);
        mergeSort (right, right.size (), tmp);
    }
}


