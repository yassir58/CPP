#include "Span.hpp"

// Constructors
Span::Span():_max(0)
{
// 	std::cout << "\e[0;33mDefault Constructor called of Span\e[0m" << std::endl;
this->_Span.reserve (0);
}
Span::Span (size_t N):_max (N)
{
}

Span::Span(const Span &copy)
{
	// std::cout << "\e[0;33mCopy Constructor called of Span\e[0m" << std::endl;
	this->_max = copy._max;
	Iter start= copy.getSpanVector().begin();
	Iter end = 	copy.getSpanVector().end ();
	this->_Span.clear ();
	try
	{
		this->AddRange (this->_Span.begin(), start, end, copy._max);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}


// Destructor
Span::~Span()
{
	// std::cout << "\e[0;31mDestructor called of Span\e[0m" << std::endl;
}


// Operators
Span & Span::operator=(const Span &assign)
{
	if (this == &assign)
		return (*this);
	this->_max = assign._max;
	Iter start= assign.getSpanVector().begin();
	Iter end = 	assign.getSpanVector().end ();
	this->_Span.clear ();
	try
	{
		this->AddRange (this->_Span.begin(), start, end, assign._max);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return *this;
}

const char *OutOfRange::what () const throw ()
{
	return ("\e[0;31m << OutOfRange >> \e[0m");
}

const char *NotFound::what () const throw ()
{
	return ("\e[0;31m << NotFound >> \e[0m");
}

void Span::addNumber (int number)
{
	if (this->_Span.size () < this->_max)
		this->_Span.push_back(number);
	else 
		throw OutOfRange();
}

void Span::printSpan (void) const
{
	typedef std::vector< const int>::iterator  Iter;

	for (Iter start = this->_Span.begin (); start != this->_Span.end (); ++start)
	{
		std::cout << *start << ' ';
	}
	std::cout <<  std::endl;
}

int getSpan (int x, int y)
{
	return (std::abs(x - y));
}

int Span::shortestSpan (void) const
{
	int tmp[this->_max];
	typedef std::vector<const int>::iterator Iter;
	Iter 	start = this->_Span.begin ();
	Iter 	end = this->_Span.end ();

	if (this->_Span.size() <= 1)
		throw NotFound();
	std::adjacent_difference (start, end, tmp, getSpan);
	int *ptr = std::min_element (tmp, tmp + this->_max);
	return (*ptr);
}

int Span::longestSpan (void) const
{
	int tmp[this->_max];
	typedef std::vector<const int>::iterator Iter;
	Iter 	start = this->_Span.begin ();
	Iter 	end = this->_Span.end ();

	if (this->_Span.size() <= 1)
		throw NotFound();
	std::adjacent_difference (start, end, tmp, getSpan);
	int *ptr = std::max_element (tmp, tmp + this->_max);
	return (*ptr);
}


const std::vector<int> &Span::getSpanVector (void) const
{
	return (this->_Span);
}

size_t Span::getMax (void) const
{
	return (this->_max);
}

void Span::AddRange (Iter indx, Iter &start, Iter &end, size_t range)
{
	if ((this->_Span.size() + range) <= this->_max || this->_max == 0)
		this->_Span.insert (indx, start, end);
	else
		throw OutOfRange();	
}
