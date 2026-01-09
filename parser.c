/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: semebrah <semebrah@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 19:37:21 by semebrah          #+#    #+#             */
/*   Updated: 2025/12/15 19:37:33 by semebrah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

void	ft_reset_template(t_template *tpl)
{
	if (!tpl)
		return ;
	tpl->start = 0;
	tpl->left = 0;
	tpl->sign = 0;
	tpl->space = 0;
	tpl->alt = 0;
	tpl->zero = 0;
	tpl->width = 0;
	tpl->precision = 0;
	tpl->specifier = 0;
	tpl->end = 0;
}

int	ft_next_template(const char *str, size_t start, t_template *tpl)
{
	size_t	i;

	i = start;
	while (str[i] && ft_index(str, i, "%") > -1)
	{
		ft_reset_template(tpl);
		tpl->start = ft_index(str, i, "%");
		i = tpl->start + 1;
		while (str[i] && ft_is_member(str[i], "-+ #0"))
		{
			if (str[i] == '-')
				tpl->left = 1;
			else if (str[i] == '+')
				tpl->sign = 1;
			else if (str[i] == ' ')
				tpl->space = 1;
			else if (str[i] == '#')
				tpl->alt = 1;
			else if (str[i] == '0')
				tpl->zero = 1;
			i++;
		}
		while (str[i] && ft_isdigit(str[i]))
			tpl->width = tpl->width * 10 + str[i++] - '0';
		if (str[i] == '.')
			i++;
		while (str[i] && ft_isdigit(str[i]))
			tpl->precision = tpl->precision * 10 + str[i++] - '0';
		if (str[i] && ft_is_member(str[i], "cspdiuxX%"))
			tpl->specifier = str[i++];
		tpl->end = i;
		if (tpl->specifier)
			return (1);
	}
	return (0);
}
