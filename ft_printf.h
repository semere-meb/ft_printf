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

#ifndef FTPRINTF_H
# define FTPRINTF_H

# include "libft/libft.h"
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_template
{
	size_t	start;
	size_t	end;

	int		left;
	int		sign;
	int		space;
	int		alt;
	int		zero;
	ssize_t	width;
	ssize_t	precision;
	char	specifier;
}			t_template;

// utils.c
int			ft_is_member(char c, char *chars);
ssize_t		ft_index(const char *s, size_t start, char *chars);
char		*ft_str_gen(char c, size_t size);

// parser.c
void		ft_reset_template(t_template *tpl);
int			ft_next_template(const char *str, size_t start, t_template *tpl);

// converter.c
char		*ft_convert_base(int n, char *base_to);

// ft_printf.c
int			ft_printf(const char *, ...);

// handler.c
size_t		handle_s(char *str, t_template *tpl);
size_t		handle_p(char *str, t_template *tpl);
size_t		handle_d(char *str, t_template *tpl);
size_t		handle_u(char *str, t_template *tpl);
size_t		handle_x(char *str, t_template *tpl);

#endif
