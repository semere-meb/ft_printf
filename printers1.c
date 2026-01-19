/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: semebrah <semebrah@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 19:36:54 by semebrah          #+#    #+#             */
/*   Updated: 2025/12/15 19:37:33 by semebrah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_c(int c, t_template *tpl)
{
	char	*str_gen;
	size_t	size;
	char	*str;

	size = 1;
	str = strgen(c, 1);
	str_gen = handle_width(tpl, 1, ' ', 0);
	size += ft_strlen(str_gen);
	str = handle_left(tpl, str, str_gen, 1);
	print(str, tpl, size);
}

void	print_s(char *str, t_template *tpl)
{
	int		zero;
	char	*str_gen;

	zero = 0;
	if (str == NULL)
	{
		zero = 1;
		str = ft_strdup("(null)");
	}
	else
		str = ft_strdup(str);
	str = handle_precision(tpl, str, zero);
	str_gen = handle_width(tpl, ft_strlen(str), ' ', 0);
	str = handle_left(tpl, str, str_gen, -1);
	print(str, tpl, ft_strlen(str));
}

void	print_p(unsigned long long val, t_template *tpl)
{
	char	*str_gen;
	char	*str;

	if (val == 0)
		str = ft_strdup("(nil)");
	else
		str = append(ft_strdup("0x"), convert(val, HEX), -1, -1);
	str_gen = handle_width(tpl, ft_strlen(str), ' ', 0);
	str = handle_left(tpl, str, str_gen, -1);
	print(str, tpl, ft_strlen(str));
}

void	print_d(long long val, t_template *tpl)
{
	char	*str_gen;
	char	pad;
	char	*str;
	int		negative;

	negative = val < 0;
	if (val < 0)
		val *= -1;
	str = convert(val, DEC);
	str = handle_precision(tpl, str, val == 0);
	pad = handle_zero(tpl);
	str = handle_sign(tpl, str, negative);
	str = handle_space(tpl, str, negative);
	str_gen = handle_width(tpl, ft_strlen(str), pad, negative);
	if (negative && pad != '0')
		str = append(ft_strdup("-"), str, -1, -1);
	str = handle_left(tpl, str, str_gen, -1);
	if (negative && pad == '0')
		str = append(ft_strdup("-"), str, -1, -1);
	print(str, tpl, ft_strlen(str));
}

void	print_u(unsigned int val, t_template *tpl)
{
	char	*str_gen;
	char	pad;
	char	*str;

	str = convert(val, DEC);
	str = handle_precision(tpl, str, val == 0);
	pad = handle_zero(tpl);
	str_gen = handle_width(tpl, ft_strlen(str), pad, 0);
	str = handle_left(tpl, str, str_gen, -1);
	print(str, tpl, ft_strlen(str));
}
