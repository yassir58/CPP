#include "./PmergeMe.hpp"

Error::Error(const char *error)
{
    err_description = error;
}

const char *Error::what(void) const throw()
{
    return (this->err_description);
}

int toInt(std::string str)
{
    int res;
    std::stringstream ss(str);
    ss >> res;
    return (res);
}

std::string toString(int number)
{
    std::stringstream ss;
    std::string str;
    ss << number;
    ss >> str;
    return (str);
}

void validateInput(std::string input)
{
    if (input.find_first_not_of("0123456789") != std::string::npos)
        throw Error("Error!");
}

std::vector<int> getVector(std::string input)
{
    std::stringstream ss(input);
    int num;
    std::string word;
    std::vector<int> vector;

    while (ss >> word)
    {
        validateInput(word);
        num = toInt(word);
        vector.push_back(num);
    }
    return (vector);
}

std::deque<int> getDeque(std::string input)
{
    std::stringstream ss(input);
    int num;
    std::string word;
    std::deque<int> deq;

    while (ss >> word)
    {
        validateInput(word);
        num = toInt(word);
        deq.push_back(num);
    }

    return (deq);
}

std::string joinArray(char *argv[])
{
    std::string str("");
    int i = 1;

    while (argv[i])
    {
        str.append(argv[i]).append(" ");
        i++;
    }
    return (str);
}

void printContainer(std::vector<int> vect)
{
    for (std::vector<int>::iterator it = vect.begin(); it != vect.end(); ++it)
        std::cout << (*it) << " ";
    std::cout << std::endl;
}

void printContainer(std::deque<int> deq)
{
    for (std::deque<int>::iterator it = deq.begin(); it != deq.end(); ++it)
        std::cout << (*it) << " ";
    std::cout << std::endl;
}

std::vector<int> partition(std::vector<int> list, int start, int end)
{
    std::vector<int> newList;

    for (int i = start; i <= end; i++)
    {
        newList.push_back(list[i]);
    }
    return newList;
}

std::deque<int> partition(std::deque<int> deq, int start, int end)
{
    std::deque<int> newDeq;

    for (int i = start; i <= end; i++)
    {
        newDeq.push_back(deq[i]);
    }
    return newDeq;
}

int getPosition(const std::vector<int> &arr, int low, int high, int target)
{
    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (arr[mid] < target)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return low;
}

int getPosition(const std::deque<int> &deq, int low, int high, int target)
{
    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (deq[mid] < target)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return low;
}

void insert(std::vector<int> &vector, std::vector<int> sub)
{

    int len = sub.size();
    int pos = 0;
    std::vector<int>::iterator it;

    if (!vector.size())
    {
        for (it = sub.begin(); it < sub.end(); it++)
            vector.push_back(*(it));
    }
    else
    {
        it = vector.end();
        for (int i = 0; i < len; i++)
        {
            pos = getPosition(vector, 0, vector.size() - 1, sub[i]);
            it = vector.begin() + pos;
            vector.insert(it, sub[i]);
        }
    }
}

void insert(std::deque<int> &deq, std::deque<int> sub)
{

    int len = sub.size();
    int pos = 0;
    std::deque<int>::iterator it;

    if (!deq.size())
    {
        for (it = sub.begin(); it < sub.end(); it++)
            deq.push_back(*(it));
    }
    else
    {
        it = deq.end();
        for (int i = 0; i < len; i++)
        {
            pos = getPosition(deq, 0, deq.size() - 1, sub[i]);
            it = deq.begin() + pos;
            deq.insert(it, sub[i]);
        }
    }
}

void mergeSort(std::vector<int> list, int len, std::vector<int> &tmp)
{

    std::vector<int> left;
    std::vector<int> right;

    int mid = 0;

    if (len <= 2)
    {
        if (len > 1)
        {
            if (list[0] > list[1])
                std::swap(list[0], list[1]);
        }
        insert(tmp, list);
    }
    else
    {
        mid = len / 2;
        left = partition(list, 0, mid - 1);
        right = partition(list, mid, len - 1);
        mergeSort(left, left.size(), tmp);
        mergeSort(right, right.size(), tmp);
    }
}

void mergeSort(std::deque<int> deq, int len, std::deque<int> &tmp)
{
    std::deque<int> left;
    std::deque<int> right;

    int mid = 0;

    if (len <= 2)
    {
        if (len > 1)
        {
            if (deq[0] > deq[1])
                std::swap(deq[0], deq[1]);
        }
        insert(tmp, deq);
    }
    else
    {
        mid = len / 2;
        left = partition(deq, 0, mid - 1);
        right = partition(deq, mid, len - 1);
        mergeSort(left, left.size(), tmp);
        mergeSort(right, right.size(), tmp);
    }
}

void sort(std::vector<int> &vect)
{
    std::vector<int> tmp;

    clock_t startTime = clock();
    mergeSort(vect, vect.size(), tmp);
    vect = tmp;
    clock_t endTime = clock();
    clock_t duration = endTime - startTime;
    std::cout << "after : ";
    printContainer(vect);
    std::cout << "Time to process a range of " << vect.size() << " elements with std::vector is : " << std::fixed << static_cast<double>(duration) / CLOCKS_PER_SEC << " seconds" << std::endl;
}

void sort(std::deque<int> &deq)
{
    std::deque<int> tmp;
    clock_t startTime = clock();
    mergeSort(deq, deq.size(), tmp);
    clock_t endTime = clock();
    clock_t duration = endTime - startTime;
    std::cout << "Time to process a range of " << deq.size() << " elements with std::deque is : " << std::fixed << static_cast<double>(duration) / CLOCKS_PER_SEC << " seconds" << std::endl;
}