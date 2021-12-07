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

void Span::addNumber(long long int num)
{
    std::string str;
    std::stringstream tmp;
	long long int gap;
    
	if (arr.size() == N)
	{
		tmp << N;
    	str = tmp.str();
		throw std::invalid_argument("Already " + str + " of them stored");
	}
	if (num < INT_MIN || num > INT_MAX)
	{
		tmp << num;
    	str = tmp.str();
		throw std::invalid_argument(str + " is Out of int range");
	}
	arr.push_back(num);
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

void Span::addNumber(std::vector<int>::const_iterator first, std::vector<int>::const_iterator last)
{
	std::string str;
    std::stringstream tmp;
	long long int gap;
    
	while (first < last)
	{
		if (arr.size() == N)
		{
			tmp << N;
			str = tmp.str();
			throw std::invalid_argument("Already " + str + " of them stored");
		}
		if (*first < INT_MIN || *first > INT_MAX)
		{
			tmp << *first;
			str = tmp.str();
			throw std::invalid_argument(str + " is Out of int range");
		}
		arr.push_back(*first);
		if (arr.size() > 1)
		{
			gap = static_cast<long long int> (*(arr.end() - 2)) \
					- static_cast<long long int> (*(arr.end() - 1));
			if (gap < 0)
				gap *= -1;
			shortspan = std::min(shortspan, gap);
			longspan = std::max(longspan, gap);
		}
		first++;
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