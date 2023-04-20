#include "./RPN.hpp"


std::stack<std::string> getStack (std::string input)
{
    std::stack <std::string> tmp;
    std::stack <std::string> rpnStack;
    std::stringstream ss(input);
    std::string word;


    while (ss >> word)
    {
        validateInput (word);
        tmp.push (word);
    }
    while (tmp.size ())
    {
        rpnStack.push (tmp.top());
        tmp.pop();
    }
    return (rpnStack);
}
Error::Error (const char *error)
{
    err_description = error;
}

const char *Error::what (void) const throw()
{
    return (this->err_description);
}

void validateInput (std::string input)
{
    std::stringstream ss(input);
    int number;

    if (input.find_first_not_of ("0123456789+-/*") != std::string::npos)
        throw Error ("Error!");
    ss >> number;
    if (number > 10)
        throw Error("Error!");
}


int calculate(int a, int b, std::string op)
{
    int result = 0;
    if (!op.compare ("*"))
        result = a * b;
    else if (!op.compare ("+"))
        result  = a + b;
    else if (!op.compare("-"))
        result = a-b;
    else if (!op.compare ("/"))
        result = a / b;
    return (result);
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

void printStack (std::stack<std::string > stack)
{
    while (stack.size () > 0)
    {
        std::cout <<  "=> |" << stack.top () << "|" <<  std::endl;
        stack.pop ();
    }
}
int RPN(std::stack <std::string> rpnStack)
{
    int result  =  0;
    int a = 0, b= 0;
    std::string op;
    
   
    while (rpnStack.size () > 1)
    {
        a = toInt (rpnStack.top()) , rpnStack.pop();
        b = toInt (rpnStack.top()) , rpnStack.pop();
        op =  rpnStack.top(), rpnStack.pop();
        result = calculate(a, b, op);
        rpnStack.push(toString (result));
    }
    return (result);
}

