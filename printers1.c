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
#include "libft/libft.h"

void	print_c(int c, t_template *tpl)
{
	char	*str_gen;
	size_t	size;
	char	*str;

	size = 1;
	str = strgen(c, 1);
	str_gen = handle_width(tpl, 1, ' ');
	size += ft_strlen(str_gen);
	str = handle_left(tpl, str, str_gen, 1);
	print(str, tpl, size);
}

void	print_s(char *str, t_template *tpl)
{
	int zero = 0;
	char	*str_gen;

	if (str == NULL){
		zero = 1;
		str = ft_strdup("(null)");
	}
	else
		str = ft_strdup(str);
	str = handle_precision(tpl, str, zero, 0);
	str_gen = handle_width(tpl, ft_strlen(str), ' ');
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
	str_gen = handle_width(tpl, ft_strlen(str), ' ');
	str = handle_left(tpl, str, str_gen, -1);
	print(str, tpl, ft_strlen(str));
}

void	print_d(long long val, t_template *tpl)
{
	char	*str_gen;
	char	pad;
	char	*str;
	int negative = 0;

	if (val < 0) {
		negative = 1;
		val *= -1;
	}

	str = convert(val, DEC);
	str = handle_precision(tpl, str, val == 0, negative);
	pad = handle_zero(tpl);
	str = handle_sign(tpl, str);
	str = handle_space(tpl, str);
	if (negative)
		str = append(ft_strdup("-"), str, -1, -1);
	str_gen = handle_width(tpl, ft_strlen(str), pad);
	str = handle_left(tpl, str, str_gen, -1);
	print(str, tpl, ft_strlen(str));
}

void	print_u(unsigned int val, t_template *tpl)
{
	char	*str_gen;
	char	pad;
	char	*str;

	str = convert(val, DEC);
	str = handle_precision(tpl, str, val == 0, 0);
	pad = handle_zero(tpl);
	str_gen = handle_width(tpl, ft_strlen(str), pad);
	str = handle_left(tpl, str, str_gen, -1);
	print(str, tpl, ft_strlen(str));
}
