/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonkang <sonkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 00:56:56 by sonkang           #+#    #+#             */
/*   Updated: 2021/04/21 20:38:23 by sonkang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>

typedef	struct	s_info {
	int			minus;
	int			zero;
	int			precision;
	int			width;
	char		spec;
}				t_info;

/*
*****************************   MAIN FUNCTION   *******************************
*/

int				ft_printf(const char *format, ...);
int				info_check(const char *format, t_info *info, va_list ap, int i);
int				head_check(const char *format, t_info *info, va_list ap, int i);
void			set_info(t_info *info);
int				print_format(const char *format, int i,
				va_list ap, t_info *info);
int				print_all(const char *format, int i, va_list ap, t_info *info);

/*
*****************************   PRINT FUNCTION   *******************************
*/

int				print_scper(va_list ap, t_info *info, char c);
int				print_p(va_list ap, t_info *info);
int				print_num(va_list ap, t_info *info);
int				print_u(va_list ap, t_info *info);
int				print_x(va_list ap, t_info *info, char type);

/*
**************************   PRINT UTILS FUNCTION   ****************************
*/

char			*ft_ten(int n, t_info *info, int *count);
char			*ft_unsigned_ten(unsigned int n, t_info *info, int *count);
char			*ten_to_hex(unsigned int hex, int *len);
int				count_p(size_t p);
char			*ft_p(size_t p, t_info *info, int *len);
int				count_hex(unsigned int hex);
char			*ft_x(unsigned int hex, t_info *info, int *len, char type);
int				print_str(char *s, int *len, t_info *info);
int				ft_count(char **s, va_list ap, t_info *info, int *flag);
int				print_char(va_list ap);
int				itoa_count(int n);
void			fill_str(char *str, int n, int count, int prec);
void			fill_p(char *str, size_t p, int len);
int				itoa_unsigned_count(unsigned int n);
void			fill_unsigned_s(char *str, unsigned int n, int count, int prec);
void			fill_x(char *str, unsigned int hex, int len);
int				print_scper_head(int *len, t_info *info, char type);
int				print_scper_back(int len, t_info *info, char type);

/*
*****************************   UTILS FUNCTION   *******************************
*/

int				ft_isdigit(int c);
void			ft_bzero(void *s, size_t n);
char			*ft_strdup(const char *s1);
size_t			ft_strlen(const char *s);
void			*ft_calloc(size_t count, size_t size);
int				ft_write(int ret, char *s);

#endif
