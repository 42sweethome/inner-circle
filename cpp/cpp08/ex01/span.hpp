#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <vector>
# include <sstream>
# include <limits>


class Span
{
	private:
		std::vector<int> arr;
		unsigned int N;
		long long int shortspan;
		long long int longspan;

	public:
        Span();
        Span(unsigned int n);
        Span(const Span &src);
        ~Span();

        Span & operator=(const Span &src);
		
		void addNumber(long long int n);
		void addNumber(std::vector<int>::const_iterator first, std::vector<int>::const_iterator last);
		long long int shortestSpan();
    	long long int longestSpan();
		std::vector<int>::iterator ret_begin();
};

#endif
