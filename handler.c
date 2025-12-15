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

size_t	handle_s(char *str, t_template *tpl)
{
	ssize_t	size;
	char	*gen;

	size = ft_strlen(str);
	if (tpl->precision < size)
		size = tpl->precision;
	gen = ft_str_gen(' ', tpl->width - size);
	if (tpl->left && tpl->width > size)
		write(1, gen, ft_strlen(gen));
	write(1, str, size);
	if (!tpl->left && tpl->width > size)
		write(1, gen, ft_strlen(gen));
	return (ft_strlen(gen) + size);
}

size_t	handle_d(char *str, t_template *tpl)
{
	(void)str, (void)tpl;
	return (0);
}
size_t	handle_u(char *str, t_template *tpl)
{
	(void)str, (void)tpl;
	return (0);
}
size_t	handle_x(char *str, t_template *tpl)
{
	(void)str, (void)tpl;
	return (0);
}
