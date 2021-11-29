#ifndef CONVERSION_HPP
# define CONVERSION_HPP

# include <iostream>
# include <string>
# include <cctype>
# include <cstdlib>
# include <climits>
# include <iomanip>

class Conversion
{
	private:
		int sign;
		int point;
		int isfloat;
		int pseudo;
		int isstring;
		int ischar;
		int isprint;
		int d_zero;
		int f_zero;
		float fnum;
		double dounum;
		char *argv;

	public:
		Conversion();
        Conversion(const Conversion &src);
        Conversion(char *argv);
        Conversion& operator= (const Conversion &src);
        ~Conversion();
		void check_param();
		int check_num(int i);
		int get_num_info(int idx);
		int ft_strlen();
		void check_isprint();
		int check_pseudo();
		void check_string();
		void classify_ntype();
		void classify_type();
};

#endif
