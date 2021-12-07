#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iostream>
# include <stack>
# include <list>
# include <deque>

template<typename T>
class MutantStack : public std::stack<T>
{
    public:
        MutantStack(){};
        MutantStack(MutantStack const &src);
        ~MutantStack(){};
        MutantStack<T>& operator=(MutantStack const &src);

        typedef typename std::stack<T>::container_type::iterator iterator;
        MutantStack<T>::iterator begin();
        MutantStack<T>::iterator end();
};

template<typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin()
{
    return (MutantStack<T>::c.begin());
}

template<typename T>
typename MutantStack<T>::iterator MutantStack<T>::end()
{
    return (this->c.end());
}

template<typename T>
MutantStack<T>::MutantStack(MutantStack const &src) : std::stack<T>(src)
{

}

template<typename T>
MutantStack<T>& MutantStack<T>::operator=(MutantStack const &src)
{
    this->c = src.c;
    return (*this);
}
#endif