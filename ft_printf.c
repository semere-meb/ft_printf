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
#include <stdarg.h>
#include <stdio.h>

int	ft_printf(const char *f, ...)
{
	size_t		i;
	t_template	*tpl;
	va_list		args;
	size_t		count;

	i = 0;
	tpl = malloc(sizeof(t_template));
	count = 0;
	va_start(args, f);
	while (f[i] && ft_next_template(f, i, tpl))
	{
		write(1, &f[i], tpl->start - i);
		count += (tpl->start - i);
		if (tpl->specifier == 'c')
			count += handle_s((char[]){va_arg(args, int)}, tpl);
		else if (tpl->specifier == 's')
			count += handle_s(va_arg(args, char *), tpl);
		else if (tpl->specifier == 'd' || tpl->specifier == 'i')
			count += handle_d(ft_convert_base(va_arg(args, int), "0123456789"),
					tpl);
		else if (tpl->specifier == 'u')
			count += handle_u(ft_convert_base(va_arg(args, unsigned int),
						"0123456789abcdef"), tpl);
		else if (tpl->specifier == 'x')
			count += handle_x(ft_convert_base(va_arg(args, int),
						"0123456789ABCDEF"), tpl);
		else if (tpl->specifier == 'x' || tpl->specifier == 'p')
			count += handle_x(ft_convert_base(va_arg(args, int),
						"0123456789abcdef"), tpl);
		else if (tpl->specifier == '%')
		{
			write(1, "%", 1);
			count += 1;
		}
		i = tpl->end;
	}
	va_end(args);
	free(tpl);
	write(1, &f[i], ft_strlen(&f[i]));
	return (count);
}
