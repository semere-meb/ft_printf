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
	char *temp;
	char *res;

	i = 0;
	tpl = malloc(sizeof(t_template));
	res = ft_strdup("");
	va_start(args, f);

	while (f[i] && ft_next_template(f, i, tpl))
	{
		res = append(res, (char *)&f[i], tpl->start - i, 0);
		if (tpl->specifier == 'c')
			temp = handle_c(va_arg(args, int), tpl);
		else if (tpl->specifier == 's')
			temp = handle_s(va_arg(args, char *), tpl);
		else if (tpl->specifier == 'd' || tpl->specifier == 'i')
			temp = handle_d(base(va_arg(args, int), "0123456789"), tpl);
		else if (tpl->specifier == 'u')
			temp = handle_u(base(va_arg(args, unsigned int), "0123456789abcdef"), tpl);
		else if (tpl->specifier == 'X')
			temp = handle_x(base(va_arg(args, int), "0123456789ABCDEF"), tpl);
		else if (tpl->specifier == 'x' || tpl->specifier == 'p')
			temp = handle_x(base(va_arg(args, int), "0123456789abcdef"), tpl);
		else if (tpl->specifier == '%')
			temp = ft_strdup("%");
		i = tpl->end;
		res = append(res, temp, ft_strlen(temp), 1);
	}
	res = append(res, (char *)&f[i], ft_strlen(&f[i]), 0);
	ft_putstr_fd(res, 1);
	i = ft_strlen(res);

	va_end(args);
	free(tpl);
	free(res);

	return (i);
}
