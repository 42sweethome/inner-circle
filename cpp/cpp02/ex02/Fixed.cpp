#include "Fixed.hpp"

Fixed::Fixed()
{
	point_value = 0;
}

Fixed::Fixed(const int num)
{
	point_value = (int)(roundf(num << frac_bits));
}

Fixed::Fixed(const float num)
{
	point_value = (int)(roundf(num * (1 << frac_bits)));
}

Fixed::Fixed(const Fixed &src)
{
	*this = src;
}

Fixed::~Fixed()
{
}

Fixed & Fixed::operator=(const Fixed &src)
{
	if (this != &src)
	{
		this->point_value = src.point_value;
	}
	return (*this);
}

bool Fixed::operator<(const Fixed &src) const
{
	if (point_value < src.point_value)
		return (1);
	else
		return (0);
}

bool Fixed::operator>(const Fixed &src) const
{
	if (point_value > src.point_value)
		return (1);
	else
		return (0);
}

bool Fixed::operator<=(const Fixed &src) const
{
	if (point_value <= src.point_value)
		return (1);
	else
		return (0);
}

bool Fixed::operator>=(const Fixed &src) const
{
	if (point_value >= src.point_value)
		return (1);
	else
		return (0);
}

bool Fixed::operator==(const Fixed &src) const
{
	if (point_value == src.point_value)
		return (1);
	else
		return (0);
}

bool Fixed::operator!=(const Fixed &src) const
{
	if (point_value != src.point_value)
		return (1);
	else
		return (0);
}

Fixed Fixed::operator+(const Fixed &src) const
{
	return (Fixed (toFloat() + src.toFloat()));
}

Fixed Fixed::operator-(const Fixed &src) const
{
	return (Fixed (toFloat() - src.toFloat()));
}

Fixed Fixed::operator*(const Fixed &src) const
{
	return (Fixed (toFloat() * src.toFloat()));
}

Fixed Fixed::operator/(const Fixed &src) const
{
	if (src.toFloat() == 0)
	{
		std::cout << "can't divide by ";
		return (0);
	}
	else
		return (Fixed (toFloat() / src.toFloat()));
}

Fixed& Fixed::operator++()
{
	point_value = point_value + 1;
	return (*this);
}

Fixed& Fixed::operator--()
{
	point_value = point_value - 1;
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed copy(*this);
	point_value = point_value + 1;
	return (copy);
}

Fixed Fixed::operator--(int)
{
	Fixed copy(*this);
	point_value = point_value - 1;
	return (copy);
}

std::ostream & operator<<(std::ostream& os, const Fixed &src)
{
	os << src.toFloat();
	return (os);
}

int Fixed::getRawBits(void) const
{
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

Fixed & Fixed::min(Fixed & src1, Fixed & src2)
{
	std::cout << "(min)";
	if (src1.toFloat() < src2.toFloat())
		return (src1);
	else
		return (src2);
}

Fixed & Fixed::max(Fixed & src1, Fixed & src2)
{
	std::cout << "(max)";
	if (src1.toFloat() > src2.toFloat())
		return (src1);
	else
		return (src2);
}

const Fixed & Fixed::min(const Fixed & src1, const Fixed & src2)
{
	std::cout << "(const min)";
	if (src1.toFloat() < src2.toFloat())
		return (src1);
	else
		return (src2);
}

const Fixed & Fixed::max(const Fixed & src1, const Fixed & src2)
{
	std::cout << "(const max)";
	if (src1.toFloat() > src2.toFloat())
		return (src1);
	else
		return (src2);
}