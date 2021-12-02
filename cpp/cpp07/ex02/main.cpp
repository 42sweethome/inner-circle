#include "Array.hpp"

int main(int, char**)
{
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        Array<int> copy1 = numbers;
        Array<int> copy2(copy1);
        Array<int> assign;
        assign = copy2;
        std::cout << std::endl;

        copy1[10] = 10;
        copy1[100] = 100;
        for (int i = 0; i < MAX_VAL; i++)
        {
            if (copy1[i] != numbers[i])
            {
                std::cerr << "didn't save the same value!!" << std::endl;
                std::cerr << "copy1 : " << copy1[i] << " numbers : " << numbers[i] << std::endl;
            }
            if (copy1[i] != copy2[i])
            {
                std::cerr << "didn't save the same value!!" << std::endl;
                std::cerr << "copy1 : " << copy1[i] << " copy2 : " << copy2[i] << std::endl;
            }
            if (copy1[i] != assign[i])
            {
                std::cerr << "didn't save the same value!!" << std::endl;
                std::cerr << "copy1 : " << copy1[i] << " assign : " << assign[i] << std::endl;
            }
        }
        std::cout << std::endl;
    }
    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 127;
        std::cout << numbers[-2] <<std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << std::endl;
    delete [] mirror;//
    return 0;
}
