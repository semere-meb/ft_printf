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
#include <stdio.h>

// TODO: remember precion of 0 for 0 

void inspect_tpl(t_template *tpl) {
	dprintf(1, "left     : [%i]\n", tpl->left);
	dprintf(1, "sign     : [%i]\n", tpl->sign);
	dprintf(1, "space    : [%i]\n", tpl->space);
	dprintf(1, "alt      : [%i]\n", tpl->alt);
	dprintf(1, "zero     : [%i]\n", tpl->zero);
	dprintf(1, "width    : [%i]\n", tpl->width);
	dprintf(1, "precision: [%i]\n", tpl->precision);
	dprintf(1, "specifier: [%c]\n", tpl->specifier);
}

char *handle_c(int c, t_template *tpl) {
	char *str = ft_str_gen(c, 1);
	char *str_gen = ft_strdup("");

	if(tpl->width > 1){
		free(str_gen);
		str_gen = ft_str_gen(' ', tpl->width -1);
	}
	if (tpl->left)
		return append(str, str_gen, ft_strlen(str_gen), 1);
	return append(str_gen, str, ft_strlen(str), 1);
}

char *handle_s(char *str, t_template *tpl)  {
	char *str_gen = ft_strdup("");
	char *temp = ft_strdup(str);

	if (tpl->precision && tpl->precision < (int) ft_strlen(str_gen))
		temp[tpl->precision] = '\0';

	if(tpl->width > (int) ft_strlen(temp)){
		free(str_gen);
		str_gen = ft_str_gen(' ', tpl->width - (int) ft_strlen(temp));
	}
	if (tpl->left)
		return append(temp, str_gen, ft_strlen(str_gen), 1);
	return append(str_gen, temp, ft_strlen(str), 1);
}

char *handle_p(char *str, t_template *tpl)   {
	char *str_gen = ft_strdup("");
	str = append(ft_strdup("0x"), str, ft_strlen(str), 1);

	if(tpl->width > (int) ft_strlen(str)){
		free(str_gen);
		str_gen = ft_str_gen(' ', tpl->width - (int) ft_strlen(str));
	}
	if (tpl->left)
		return append(str, str_gen, ft_strlen(str_gen), 1);
	return append(str_gen, str, ft_strlen(str), 1);
}

char *handle_d(char *str, t_template *tpl) {
	if (tpl->sign && str[0] != '-')
		str = append(ft_strdup("-"), str, ft_strlen(str), 1);
	else if (tpl->space && str[0] != '-')
		str = append(ft_strdup(" "), str, ft_strlen(str), 1);

	char *str_gen = ft_strdup("");

	if (tpl->precision > (int) ft_strlen(str))
		str = append(ft_str_gen('0', tpl->precision - ft_strlen(str)), str, ft_strlen(str), 1);
	
	if(tpl->width > (int) ft_strlen(str)){
		free(str_gen);
		char c = ' ';
		if (tpl->zero && !tpl->left && !tpl->precision)
			c = '0';
		str_gen = ft_str_gen(c, tpl->width - (int) ft_strlen(str));
	}

	if (tpl->left)
		return append(str, str_gen, ft_strlen(str_gen), 1);
	return append(str_gen, str, ft_strlen(str), 1);
}

char *handle_u(char *str, t_template *tpl) {
	(void ) tpl;
	return ft_strdup(str);	
}

char *handle_x(char *str, t_template *tpl) {
	char *str_gen = ft_strdup("");

	if (tpl->precision > (int) ft_strlen(str))
		str = append(ft_str_gen('0', tpl->precision - ft_strlen(str)), str, ft_strlen(str), 1);
	
	if (tpl->alt)
		str = append(ft_strdup("0x"), str, ft_strlen(str), 1);

	if(tpl->width > (int) ft_strlen(str)){
		free(str_gen);
		char c = ' ';
		if (tpl->zero && !tpl->left && !tpl->precision)
			c = '0';
		str_gen = ft_str_gen(c, tpl->width - (int) ft_strlen(str));
	}

	if (tpl->left)
		return append(str, str_gen, ft_strlen(str_gen), 1);
	return append(str_gen, str, ft_strlen(str), 1);
}
