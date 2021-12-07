# include "mutantstack.hpp"

int main()
{
    std::cout << "-----MutantStack-----" << std::endl;

    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << mstack.top() << std::endl;
    mstack.pop();
    std::cout << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    //[...]
    mstack.push(0);
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }

    std::cout << "-----copy-----" << std::endl;
    MutantStack<int> cstack(mstack);

    MutantStack<int>::iterator c_it = cstack.begin();
    MutantStack<int>::iterator c_ite = cstack.end();

    while (c_it != c_ite)
    {
        std::cout << *c_it << std::endl;
        ++c_it;
    }

    std::cout << "-----stack-----" << std::endl;

    std::stack<int> s(mstack);

    while (!s.empty())
    {
        std::cout << s.top() << std::endl;
        s.pop();
    }

    std::cout << "-----list-----" << std::endl;

    std::list<int> list;
    list.push_back(5);
    list.push_back(17);
    std::cout << list.back() << std::endl;
    list.pop_back();
    std::cout << list.size() << std::endl;
    list.push_back(3);
    list.push_back(5);
    list.push_back(737);
    //[...]
    list.push_back(0);
    std::list<int>::iterator l_it = list.begin();
    std::list<int>::iterator l_ite = list.end();
    ++l_it;
    --l_it;
    while (l_it != l_ite)
    {
        std::cout << *l_it << std::endl;
        ++l_it;
    }
    return (0);
}