#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <string>
# include <vector>
# include <algorithm>
#include <numeric>

typedef std::vector<const int>::iterator Iter;

class OutOfRange : public std::exception
{
	public:
		virtual const char * what () const throw ();
};

class NotFound : public std::exception
{
	public:
		virtual const char * what () const throw ();
};

class Span
{
	private:
		std::vector<int> _Span;
		size_t _max;
	public:
		// Constructors
		Span();
		Span (size_t N);
		Span(const Span &copy);
		
		// Destructor
		~Span();
		
		// Operators
		Span & operator=(const Span &assign);
		void addNumber (int number);
		int shortestSpan (void) const ;
		int longestSpan (void) const ;
		void printSpan (void) const ;
		const std::vector<int> &getSpanVector (void) const;
		void AddRange (Iter pos, Iter &start, Iter &end, size_t range);
		size_t getMax (void) const;
};

#endif
