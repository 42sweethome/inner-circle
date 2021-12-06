# include "span.hpp"

Span::Span()
{
	N = 0;
	shortspan = 4294967295;
	longspan = 0;
}

Span::Span(unsigned int n)
{
	N = n;
	shortspan = 4294967295;
	longspan = 0;
}

Span::Span(const Span &src)
{
	*this = src;
}

Span::~Span()
{

}

Span & Span::operator=(const Span &src)
{
	if (this != &src)
	{
		arr = src.arr;
		N = src.N;
		shortspan = src.shortspan;
		longspan = src.longspan;
	}
	return (*this);
}

void Span::addNumber(long long int n)
{
    std::string str;
    std::stringstream num;
	long long int gap;
    
    num << N;
    str = num.str();

	if (arr.size() == N)
		throw std::invalid_argument("already " + str + " of them stored");
	arr.push_back(n);
	if (arr.size() > 1)
	{
		gap = static_cast<long long int> (*(arr.end() - 2)) \
				- static_cast<long long int> (*(arr.end() - 1));
		if (gap < 0)
			gap *= -1;
		shortspan = std::min(shortspan, gap);
		longspan = std::max(longspan, gap);
	}
}

long long int Span::shortestSpan()
{
	if (arr.size() < 2)
		throw (std::invalid_argument("argument shortage"));
	return (shortspan);
}

long long int Span::longestSpan()
{
	if (arr.size() < 2)
		throw (std::invalid_argument("argument shortage"));
	return (longspan);
}

std::vector<int>::iterator Span::ret_begin()
{
	return (arr.begin());
}
