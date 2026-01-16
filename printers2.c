/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printers2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: semebrah <semebrah@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 19:36:54 by semebrah          #+#    #+#             */
/*   Updated: 2025/12/15 19:37:33 by semebrah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_x(unsigned int val, t_template *tpl)
{
	char	*str_gen;
	char	pad;
	char	*str;

	if (tpl->specifier == 'x')
		str = convert(val, HEX);
	else
		str = convert(val, HEXCAPS);
	pad = handle_zero(tpl);
	str = handle_precision(tpl, str, val == 0);
	str = handle_alt(tpl, str);
	str_gen = handle_width(tpl, ft_strlen(str), pad, 0);
	str = handle_left(tpl, str, str_gen, -1);
	print(str, tpl, ft_strlen(str));
}

void	print(char *str, t_template *tpl, size_t size)
{
	tpl->len += size;
	write(1, str, size);
	free(str);
}
