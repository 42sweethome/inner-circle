#ifndef FIXED_HPP
# define FIXED_HPP
# include <iostream>
# include <cmath>

class Fixed
{
	private:
		int point_value;
		static const int frac_bits = 8;

	public:
		Fixed();
		~Fixed();
		Fixed(const Fixed &src);
		Fixed(const int num);
		Fixed(const float num);
		Fixed & operator=(const Fixed &src);

		bool operator<(const Fixed &src) const;
		bool operator>(const Fixed &src) const;
		bool operator<=(const Fixed &src) const;
		bool operator>=(const Fixed &src) const;
		bool operator==(const Fixed &src) const;
		bool operator!=(const Fixed &src) const;

		Fixed operator+(const Fixed &src) const;
		Fixed operator-(const Fixed &src) const;
		Fixed operator*(const Fixed &src) const;
		Fixed operator/(const Fixed &src) const;

		Fixed& operator++();
		Fixed& operator--();
		Fixed operator++(int);	
		Fixed operator--(int);	

		int getRawBits(void) const;
		void setRawBits(int const raw);
		int toInt(void) const;
		float toFloat(void) const;

		static Fixed & min(Fixed & src1, Fixed & src2);	
		static Fixed & max(Fixed & src1, Fixed & src2);	
		static const Fixed & min(const Fixed & src1, const Fixed & src2);
		static const Fixed & max(const Fixed & src1, const Fixed & src2);

};

std::ostream & operator<<(std::ostream& os, const Fixed &src);

#endif
