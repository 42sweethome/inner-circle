#include "Fixed.hpp"

Fixed::Fixed()
{
    std::cout << "Default constructor called" << std::endl;
    point_value = 0;
}

Fixed::Fixed(const int num)
{
    std::cout << "Int constructor called" << std::endl;
    point_value = (int)(roundf(num << frac_bits));
}

Fixed::Fixed(const float num)
{
    std::cout << "Float constructor called" << std::endl;
    point_value = (int)(roundf(num * (1 << frac_bits)));
}

Fixed::Fixed(const Fixed &src)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = src;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

Fixed & Fixed::operator=(const Fixed &src)
{
    std::cout << "Assignation operator called" << std::endl;
    if (this != &src)
    {
        this->point_value = src.point_value;
    }
    return (*this);
}

std::ostream & operator<<(std::ostream& os, const Fixed &src)
{
    os << src.toFloat();
    return (os);
}

int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return (this->point_value);
}

void Fixed::setRawBits(int const raw)
{
    this->point_value = raw;
}

int Fixed::toInt(void) const
{
    return (point_value >> frac_bits);
}

float Fixed::toFloat(void) const
{
    return ((float)point_value / (float)(1 << frac_bits));
}
