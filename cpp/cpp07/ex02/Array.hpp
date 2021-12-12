#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>
# define MAX_VAL 750

template <typename T> 
class Array
{
    private:
        T *arr;
        size_t arr_size;
    public:
        Array();
        Array(unsigned int n);
        Array(const Array &src);
        ~Array();
        Array& operator=(const Array &src);
        size_t size() const;
        T& operator[](size_t n);
};

template <typename T> 
Array<T>::Array()
{
    arr = new T[0];
    arr_size = 0;
    std::cout << "Create Array" << std::endl;
}

template <typename T> 
Array<T>::Array(unsigned int n)
{
    arr = new T[n];
    arr_size = n;
    std::cout << "Create Array" << std::endl;
}

template <typename T> 
Array<T>::Array(const Array &src)
{
    if (this != &src)
    {
        arr_size = src.size();
        this->arr = new T[arr_size];
        for (size_t i = 0; i < arr_size; i++)
        {
            arr[i] = src.arr[i];
        }
    }
    std::cout << "Create Copy Array" << std::endl;
}

template <typename T> 
Array<T>& Array<T>::operator=(const Array &src)
{
    if (this != &src)
    {
        delete[] this->arr;
        arr_size = src.size();
        this->arr = new T[arr_size];
        for (size_t i = 0; i < arr_size; i++)
        {
            arr[i] = src.arr[i];
        }
    }
    std::cout << "Create copy assign Array" << std::endl;
    return (*this);
}

template <typename T> 
Array<T>::~Array()
{
    delete[] arr;
    std::cout << "Delete Array" << std::endl;   
}

template <typename T> 
size_t Array<T>::size() const
{
    return (arr_size);
}

template <typename T> 
T& Array<T>::operator[](size_t n)
{
    if (n < 0 || n >= MAX_VAL)
        throw (std::exception ());
    return (arr[n]);
}

#endif
