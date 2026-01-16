/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: semebrah <semebrah@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 17:24:20 by semebrah          #+#    #+#             */
/*   Updated: 2025/12/15 19:37:33 by semebrah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

# define DEC "0123456789"
# define HEX "0123456789abcdef"
# define HEXCAPS "0123456789ABCDEF"

typedef struct s_template
{
	size_t	start;
	size_t	end;

	size_t	len;

	int		left;
	int		sign;
	int		space;
	int		alt;
	int		zero;
	int		width;
	int		precision;
	char	specifier;
}			t_template;

// ft_printf.c
int			ft_printf(const char *f, ...);

// parser.c
void		ft_reset_template(t_template *tpl);
int			ft_next_template(const char *str, size_t start, t_template *tpl);

// converter.c
char		*convert(unsigned long long n, char *base_to);

// utils.c
int			ft_is_member(char c, char *chars);
ssize_t		ft_index(const char *s, size_t start, char *chars);
char		*strgen(char c, size_t size);
char		*append(char *s1, char *s2, ssize_t s1size, ssize_t s2size);

// printers1.c
void		print_c(int c, t_template *tpl);
void		print_s(char *str, t_template *tpl);
void		print_p(unsigned long long val, t_template *tpl);
void		print_d(long long val, t_template *tpl);
void		print_u(unsigned int val, t_template *tpl);

// printers2.c
void		print_x(unsigned int val, t_template *tpl);
void		print(char *str, t_template *tpl, size_t size);

// handlers1.c
char		*handle_precision(t_template *tpl, char *str, int zero);
char		*handle_width(t_template *tpl, int size, char c, int negative);
char		*handle_left(t_template *tpl, char *str, char *str_gen,
				size_t str_size);
char		*handle_alt(t_template *tpl, char *str);
char		*handle_sign(t_template *tpl, char *str, int negative);

// handlers2.c
char		*handle_space(t_template *tpl, char *str, int negative);
char		handle_zero(t_template *tpl);

#endif
