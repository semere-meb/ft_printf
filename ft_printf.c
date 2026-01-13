/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: semebrah <semebrah@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 17:23:48 by semebrah          #+#    #+#             */
/*   Updated: 2025/12/15 19:37:33 by semebrah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"
#include <stdarg.h>
#include <stdio.h>

int	ft_printf(const char *f, ...)
{
	size_t		i;
	t_template	*tpl;
	va_list		args;

	i = 0;
	tpl = malloc(sizeof(t_template));
	tpl->len = 0;
	va_start(args, f);

	while (f[i] && ft_next_template(f, i, tpl))
	{
		write(1, &f[i], tpl->start - i);
		tpl->len += (tpl->start - i);
		if (tpl->specifier == 'c')
			print_c(va_arg(args, int), tpl);
		else if (tpl->specifier == 's')
			print_s(va_arg(args, char *), tpl);
		else if (tpl->specifier == 'd' || tpl->specifier == 'i')
			print_d(base(va_arg(args, int), "0123456789"), tpl);
		else if (tpl->specifier == 'u')
			print_u(base(va_arg(args, unsigned int), "0123456789"), tpl);
		else if (tpl->specifier == 'p'){
			long long val = (long long) va_arg(args, void *);
			char *res = base(val, "0123456789abcdef");
			print_p(res, tpl);
		}
		else if (tpl->specifier == 'x')
			print_x(base(va_arg(args, unsigned int), "0123456789abcdef"), tpl);
		else if (tpl->specifier == 'X')
			print_x(base(va_arg(args, unsigned int), "0123456789ABCDEF"), tpl);
		else if (tpl->specifier == '%'){
			write(1, "%", 1);
			tpl->len++;
		}
		i = tpl->end;
	}
	write(1, &f[i], ft_strlen(&f[i]));
	tpl->len += ft_strlen(&f[i]);
	i = tpl->len;

	// TODO: handle last '%'
	va_end(args);
	free(tpl);

	return (i);
}
