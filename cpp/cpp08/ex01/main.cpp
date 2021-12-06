#include "span.hpp"

int main()
{
    Span sp = Span(5);
    Span man = Span(10000);

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
    /*std::for_each( man.ret_begin(), man.ret_begin() + 10000, std::mem_fn( Span::addNumber));
    {
        for()
    }*/
}