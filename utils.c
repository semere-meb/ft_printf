/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: semebrah <semebrah@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 17:24:25 by semebrah          #+#    #+#             */
/*   Updated: 2025/12/09 17:24:31 by semebrah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_is_member(char c, char *chars)
{
	size_t	i;

	i = 0;
	while (chars[i])
		if (chars[i++] == c)
			return (i);
	return (0);
}

ssize_t	ft_index(const char *s, size_t start, char *chars)
{
	size_t	i;

	if (!s)
		return (-1);
	i = start;
	while (!ft_is_member(s[i], chars))
		if (!s[i++])
			return (-1);
	return (i);
}
