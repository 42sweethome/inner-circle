#ifndef FIXED_HPP
# define FIXED_HPP
# include <iostream>

class Fixed
{
	public:
    Fixed();
    ~Fixed();
    Fixed(const Fixed &src);
    Fixed(const int num);
    Fixed(const float num);
    Fixed & operator=(const Fixed &src);
    Fixed & operator<<(const Fixed &src);
    int getRawBits( void ) const;
    void setRawBits( int const raw );
    float toFloat( void ) const;
    int toInt( void ) const;

    private:
    int point_value;
    static const int frac_bits = 8;
};
#endif
