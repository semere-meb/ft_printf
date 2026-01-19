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

void	dispatcher(t_template *tpl, va_list args)
{
	if (tpl->specifier == 'c')
		print_c(va_arg(args, int), tpl);
	else if (tpl->specifier == 's')
		print_s(va_arg(args, char *), tpl);
	else if (tpl->specifier == 'd' || tpl->specifier == 'i')
		print_d((long long)va_arg(args, int), tpl);
	else if (tpl->specifier == 'u')
		print_u(va_arg(args, unsigned int), tpl);
	else if (tpl->specifier == 'p')
		print_p((unsigned long long)va_arg(args, void *), tpl);
	else if (tpl->specifier == 'x' || tpl->specifier == 'X')
		print_x(va_arg(args, unsigned int), tpl);
	else if (tpl->specifier == '%')
		print(ft_strdup("%"), tpl, 1);
}

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
		dispatcher(tpl, args);
		i = tpl->end;
	}
	write(1, &f[i], ft_strlen(&f[i]));
	tpl->len += ft_strlen(&f[i]);
	i = tpl->len;
	return (va_end(args), free(tpl), i);
}
