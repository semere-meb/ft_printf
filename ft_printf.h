/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: semebrah <semebrah@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 17:24:20 by semebrah          #+#    #+#             */
/*   Updated: 2025/12/09 17:24:34 by semebrah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FTPRINTF_H
# define FTPRINTF_H

# include "libft/libft.h"
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

//%[flags][width][.precision][length]specifier
// ’-0.’
// minimum field width
// ’# +’

typedef struct s_template
{
	size_t	start;
	size_t	end;

	int		left_justify;
	int		sign;
	int		space;
	int		hash;
	int		zero;
	ssize_t	width;
	ssize_t	precision;
	char	specifier;
}			t_template;

int			ft_is_member(char c, char *chars);
ssize_t		ft_index(const char *s, size_t start, char *chars);

// parser.c
void	ft_reset_template(t_template *tpl);
int			ft_next_template(const char *str, size_t start, t_template *tpl);

// converter.c
char		*ft_convert_base(int n, char *base_to);

// ft_printf.c
void		ft_printf(const char *f, ...);

// handler.c
char *ft_str_gen(char c, size_t size);
void handler(char *val, t_template *tpl);

#endif
