/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: semebrah <semebrah@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 17:23:48 by semebrah          #+#    #+#             */
/*   Updated: 2025/12/15 19:37:33 by semebrah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*handle_space(t_template *tpl, char *str, int negative)
{
	if (tpl->space && !tpl->sign && !negative)
		return (append(ft_strdup(" "), str, -1, -1));
	return (str);
}

char	handle_zero(t_template *tpl)
{
	if (tpl->zero && !tpl->left && tpl->precision == -1)
		return ('0');
	return (' ');
}
