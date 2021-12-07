#include "span.hpp"

int main()
{
    Span sp = Span(5);

    try
    {
        sp.addNumber(5);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    Span man = Span(10000);
    
    try
    {
        std::vector<int> v;
        int x = 0;
        for (int i = 0; i < 10000; i++)
        {
            x += i;
            v.push_back(x);
        }
        man.addNumber(v.begin(), v.end());
        std::cout << man.shortestSpan() << std::endl;
        std::cout << man.longestSpan() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
}