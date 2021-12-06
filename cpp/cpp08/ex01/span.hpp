#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <vector>
# include <sstream>


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
		long long int shortestSpan();
    	long long int longestSpan();
		std::vector<int>::iterator ret_begin();
};

#endif
