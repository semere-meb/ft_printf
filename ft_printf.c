/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: semebrah <semebrah@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 17:23:48 by semebrah          #+#    #+#             */
/*   Updated: 2025/12/09 17:24:06 by semebrah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>
#include <stdio.h>

void	ft_printf(const char *f, ...)
{
	size_t		i = 0;
	t_template	*tpl = malloc(sizeof(t_template));
	va_list		args;
	char *temp;

	va_start(args, f);
	while (f[i] && ft_next_template(f, i, tpl))
	{
		write(1, &f[i], tpl->start - i);
		if (tpl->specifier == 'c')
			temp = (char[]) {(char)va_arg(args, int)};
		else if (tpl->specifier == 's')
			temp = va_arg(args, char *);
		else if (tpl->specifier == 'd' || tpl->specifier == 'i')
			temp = ft_convert_base(va_arg(args, int), "0123456789");
		else if (tpl->specifier == 'u')
			temp = ft_convert_base(va_arg(args, unsigned int), "0123456789abcdef");
		else if (tpl->specifier == 'x')
			temp = ft_convert_base(va_arg(args, int), "0123456789ABCDEF");
		else if (tpl->specifier == 'x' || tpl->specifier == 'p')
			temp = ft_convert_base(va_arg(args, int), "0123456789abcdef");
		else if (tpl->specifier == '%')
			temp = "%";

		i = tpl->end;
		write(1, temp, ft_strlen(temp));
		ft_handle()
		free(temp);
	}
	va_end(args);
	free(tpl);
	write(1, &f[i], ft_strlen(&f[i]));
}
