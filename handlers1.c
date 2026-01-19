/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: semebrah <semebrah@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 17:23:48 by semebrah          #+#    #+#             */
/*   Updated: 2025/12/15 19:37:33 by semebrah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*handle_precision(t_template *tpl, char *str, int zero)
{
	char	*str_gen;

	if (zero && tpl->precision > -1 && tpl->precision < (ssize_t)ft_strlen(str))
	{
		free(str);
		return (ft_strdup(""));
	}
	if (tpl->precision > -1)
	{
		if (tpl->specifier == 's' && tpl->precision < (int)ft_strlen(str))
			str[tpl->precision] = '\0';
		else if (ft_is_member(tpl->specifier, "diuxX")
			&& tpl->precision > (int)ft_strlen(str))
		{
			str_gen = strgen('0', tpl->precision - ft_strlen(str));
			str = append(str_gen, str, -1, -1);
		}
	}
	return (str);
}

char	*handle_width(t_template *tpl, int size, char c, int negative)
{
	if (tpl->width > 0 && tpl->width > negative + size)
		return (strgen(c, tpl->width - negative - size));
	else
		return (ft_strdup(""));
}

char	*handle_left(t_template *tpl, char *str, char *str_gen, size_t str_size)
{
	if (tpl->left)
		return (append(str, str_gen, str_size, -1));
	else
		return (append(str_gen, str, -1, str_size));
}

char	*handle_alt(t_template *tpl, char *str)
{
	char	*pad;

	pad = "0x";
	if (tpl->specifier == 'X')
		pad = "0X";
	if (tpl->alt && ft_strncmp(str, "0", ft_strlen(str)))
		return (append(ft_strdup(pad), str, 2, ft_strlen(str)));
	return (str);
}

char	*handle_sign(t_template *tpl, char *str, int negative)
{
	if (tpl->sign && !negative)
		return (append(ft_strdup("+"), str, -1, -1));
	return (str);
}
