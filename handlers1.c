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
#include "libft/libft.h"
#include <stdio.h>

char	*handle_precision(t_template *tpl, char *str, int zero, int negative)
{
	char	*str_gen;
	(void) negative;

	if (zero && tpl->precision > -1 && tpl->precision < (ssize_t) ft_strlen(str)){
		free(str);
		return ft_strdup("");
	}
	if (tpl->precision > -1)
	{
		if (tpl->specifier == 's' && tpl->precision < (int)ft_strlen(str))
			str[tpl->precision] = '\0';
		else if (ft_is_member(tpl->specifier, "diuxX")
			&& tpl->precision > (int)ft_strlen(str))
		{
			// dprintf(1, "\nDEBUG: str : [%s]", str);
			// dprintf(1, "\nDEBUG: len : [%zu]", ft_strlen(str));
			// dprintf(1, "\nDEBUG: prec: [%d]", tpl->precision);
			// dprintf(1, "\nDEBUG: diff: [%zu]\n", tpl->precision - ft_strlen(str));
			str_gen = strgen('0', tpl->precision - ft_strlen(str));
			str = append(str_gen, str, -1, -1);
		}
	}
	return (str);
}

char	*handle_width(t_template *tpl, int size, char c)
{
	if (tpl->width > 0 && tpl->width > size)
		return (strgen(c, tpl->width - size));
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
	if (tpl->alt && ft_strncmp(str, "0", ft_strlen(str)))
		return (append(ft_strdup("0x"), str, 2, ft_strlen(str)));
	return (str);
}

char	*handle_sign(t_template *tpl, char *str)
{
	if (tpl->sign && str[0] != '-')
		return (append(ft_strdup("+"), str, -1, -1));
	return (str);
}
