#ifndef ITER_HPP
# define ITER_HPP

#include <iostream>

template <typename T1>
void iter(T1 *addr, size_t len, void(*fnp)(T1))
{
    for (size_t i = 0; i < len; i++)
        fnp(addr[i]);
}

template <typename T>
void print_ele(T ele)
{
    std::cout << ele << std::endl;
}

#endif