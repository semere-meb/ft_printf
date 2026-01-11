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

void handle_c(int c, t_template *tpl) {
	size_t size = 1;
	char *str = strgen(c, 1);
	char *str_gen = ft_strdup("");

	// width
	if(tpl->width > 1){
		free(str_gen);
		str_gen = strgen(' ', tpl->width -1);
	}
	
	size += ft_strlen(str_gen);

	// left
	if (tpl->left)
		str = append(str, str_gen, 1, -1);
	else
		str = append(str_gen, str, -1, 1);

	tpl->len += size;
	write(1, str, size);
}

void handle_s(char *str, t_template *tpl)  {
	size_t size = 0;
	char *str_gen = ft_strdup("");
	str = ft_strdup(str);

	// precision
	if (tpl->precision && tpl->precision < (int) ft_strlen(str_gen))
		str[tpl->precision] = '\0';

	// width
	if(tpl->width > (int) ft_strlen(str)){
		free(str_gen);
		str_gen = strgen(' ', tpl->width - (int) ft_strlen(str));
	}

	// left
	if (tpl->left)
		str = append(str, str_gen, -1, -1);
	else
		str = append(str_gen, str, -1, -1);

	tpl->len += ft_strlen(str);
	write(1, str, ft_strlen(str));
}

void handle_p(char *str, t_template *tpl)   {
	char *str_gen = ft_strdup("");
	str = append(ft_strdup("0x"), str, ft_strlen(str), 1);

	if(tpl->width > (int) ft_strlen(str)){
		free(str_gen);
		str_gen = strgen(' ', tpl->width - (int) ft_strlen(str));
	}

	if (tpl->left)
		str = append(str, str_gen, ft_strlen(str_gen), 1);
	else
		str = append(str_gen, str, ft_strlen(str), 1);

	tpl->len += ft_strlen(str);
	write(1, str, ft_strlen(str));
}

void handle_d(char *str, t_template *tpl) {
	if (tpl->sign && str[0] != '-')
		str = append(ft_strdup("-"), str, ft_strlen(str), 1);
	else if (tpl->space && str[0] != '-')
		str = append(ft_strdup(" "), str, ft_strlen(str), 1);

	char *str_gen = ft_strdup("");

	if (tpl->precision > (int) ft_strlen(str))
		str = append(strgen('0', tpl->precision - ft_strlen(str)), str, ft_strlen(str), 1);
	
	if(tpl->width > (int) ft_strlen(str)){
		free(str_gen);
		char c = ' ';
		if (tpl->zero && !tpl->left && !tpl->precision)
			c = '0';
		str_gen = strgen(c, tpl->width - (int) ft_strlen(str));
	}

	if (tpl->left)
		str = append(str, str_gen, ft_strlen(str_gen), 1);
	else
		str = append(str_gen, str, ft_strlen(str), 1);

	tpl->len += ft_strlen(str);
	write(1, str, ft_strlen(str));
}

void handle_u(char *str, t_template *tpl) {
	(void ) tpl;
	(void) str;
}

void handle_x(char *str, t_template *tpl) {
	char *str_gen = ft_strdup("");

	if (tpl->precision > (int) ft_strlen(str))
		str = append(strgen('0', tpl->precision - ft_strlen(str)), str, ft_strlen(str), 1);
	
	if (tpl->alt)
		str = append(ft_strdup("0x"), str, ft_strlen(str), 1);

	if(tpl->width > (int) ft_strlen(str)){
		free(str_gen);
		char c = ' ';
		if (tpl->zero && !tpl->left && !tpl->precision)
			c = '0';
		str_gen = strgen(c, tpl->width - (int) ft_strlen(str));
	}

	if (tpl->left)
		str = append(str, str_gen, ft_strlen(str_gen), 1);
	else
		str = append(str_gen, str, ft_strlen(str), 1);

	tpl->len += ft_strlen(str);
	write(1, str, ft_strlen(str));
}
