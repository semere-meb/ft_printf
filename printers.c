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

void print_c(int c, t_template *tpl) {
	char *str_gen;
	size_t size = 1;
	char *str = strgen(c, 1);

	str_gen = handle_width(tpl, 1, ' ');
	size += ft_strlen(str_gen);
	str = handle_left(tpl, str, str_gen, 1, -1);

	print(str, tpl, size);
}

void print_s(char *str, t_template *tpl)  {
	char *str_gen;
	char pad;

	if (str == NULL){
		print("(null)", tpl, 6);
		return;
	}
	str = ft_strdup(str);
	pad = handle_zero(tpl);
	str = handle_precision(tpl, str);
	str_gen = handle_width(tpl, ft_strlen(str), pad);
	str = handle_left(tpl, str, str_gen, -1, -1);

	print(str, tpl, ft_strlen(str));
}

void print_p(unsigned long long val, t_template *tpl) {
	char *str_gen;
	char *str;

	if (val == 0){
		print("(nil)", tpl, 5);
		return;
	}

	str = base_unsigned(val, HEX);
	str = append(ft_strdup("0x"), str, 2, ft_strlen(str));
	str_gen = handle_width(tpl, ft_strlen(str), ' ');
	str = handle_left(tpl, str, str_gen, -1, -1 );

	print(str, tpl, ft_strlen(str));
}

void print_d(int val, t_template *tpl) {
	char *str_gen;
	char pad;
	char *str = base(val, DEC);

	// TODO: check if we need to consider the sign as a digit
	str = handle_precision(tpl, str);
	pad = handle_zero(tpl);
	str = handle_sign(tpl, str);
	str = handle_space(tpl, str);
	str_gen = handle_width(tpl, ft_strlen(str), pad);
	str = handle_left(tpl, str, str_gen, -1, -1);

	print(str, tpl, ft_strlen(str));
}

void print_u(unsigned int val, t_template *tpl) {
	char *str_gen;
	char pad;
	char *str = base_unsigned(val, DEC);

	// TODO: check if we need to consider the sign as a digit
	str = handle_precision(tpl, str);
	pad = handle_zero(tpl);
	str_gen = handle_width(tpl, ft_strlen(str), pad);
	str = handle_left(tpl, str, str_gen, -1, -1);

	print(str, tpl, ft_strlen(str));
}

void print_x(unsigned int val, t_template *tpl) {
	char *str_gen;
	char pad;
	char *str;
	
	if (tpl->specifier == 'x')
		str = base_unsigned(val, HEX);
	else
		str = base_unsigned(val, HEXCAPS);
	
	// TODO: remove pad?
	pad = handle_zero(tpl);
	str = handle_precision(tpl, str);
	str = handle_alt(tpl, str);
	str_gen = handle_width(tpl, ft_strlen(str), pad);
	str = handle_left(tpl, str, str_gen, -1, -1);

	print(str, tpl, ft_strlen(str));
}
