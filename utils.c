/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: semebrah <semebrah@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 17:24:25 by semebrah          #+#    #+#             */
/*   Updated: 2025/12/15 19:37:33 by semebrah         ###   ########.fr       */
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

char	*strgen(char c, size_t size)
{
	char	*res;

	if (!size)
		return (NULL);
	res = malloc(size + 1);
	if (!res)
		return (NULL);
	res[size] = '\0';
	while (size--)
		res[size] = c;
	return (res);
}

char	*append(char *s1, char *s2, ssize_t s1size, ssize_t s2size)
{
	char	*res;

	if (s1size == -1)
		s1size = ft_strlen(s1);
	if (s2size == -1)
		s2size = ft_strlen(s2);
	res = malloc(s1size + s2size + 1);
	if (!res)
		return (NULL);
	ft_memcpy(res, s1, s1size);
	ft_memcpy(&res[s1size], s2, s2size);
	res[s1size + s2size] = '\0';
	free(s1);
	free(s2);
	return (res);
}
