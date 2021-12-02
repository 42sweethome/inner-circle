#include "iter.hpp"

int main()
{
    int arr1[5] = {0, 1, 2, 3, 4};
    double arr2[5] = {4.1, 3.2, 2.3, 1.4, 0.5};
    std::string arr3[3] = {"hi", "I'm", "james"};

    iter(arr1, 5, print_ele);
    iter(arr2, 5, print_ele);
    iter(arr3, 3, print_ele);
}