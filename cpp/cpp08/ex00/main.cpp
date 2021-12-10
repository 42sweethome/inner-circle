#include "easyfind.hpp"

int main()
{
    int arr[] = { 10, 20, 30, 40 };

    std::vector<int> myarr1 (arr, arr + 4);
    std::vector<int>::iterator it1;
    try
    {
        it1 = easyfind(myarr1, 5);
        std::cout << "Element found in myvector: " << *it1 << '\n';
    }
	catch (std::exception& e)
    {
		std::cerr << e.what() << std::endl;
    }

    std::list<int> myarr2 (arr, arr + 4);
    std::list<int>::iterator it2;
    try
    {
        it2 = easyfind(myarr2, 20);
        std::cout << "Element found in myvector: " << *it2 << '\n';
    }
	catch (std::exception& e)
    {
		std::cerr << e.what() << std::endl;
    }

    std::deque<int> myarr3 (arr, arr + 4);
    std::deque<int>::iterator it3;
    try
    {
        it3 = easyfind(myarr3, 30);
        std::cout << "Element found in myvector: " << *it3 << '\n';
    }
	catch (std::exception& e)
    {
		std::cerr << e.what() << std::endl;
    }

    return (0);
}
