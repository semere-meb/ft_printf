/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: semebrah <semebrah@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 10:50:48 by semebrah          #+#    #+#             */
/*   Updated: 2025/11/30 20:43:06 by semebrah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_strs_len(char const *s, char c)
{
	size_t	start;
	size_t	i;
	size_t	count;

	start = 0;
	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		start = i;
		while (s[i] && s[i] != c)
			i++;
		if (i > start)
			count++;
	}
	return (count);
}

static char	*allocate_string(char const *s, int start, int end)
{
	char	*new;
	int		i;

	if (start > end)
		return (NULL);
	new = malloc((end - start + 1) * sizeof(char));
	if (!new)
		return (NULL);
	i = 0;
	while (s[start] && start < end)
		new[i++] = s[start++];
	new[i] = '\0';
	return (new);
}

static char	**allocate_array(char **array, char const *s, char c)
{
	size_t	start;
	size_t	i;
	size_t	index;

	start = 0;
	i = 0;
	index = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		start = i;
		while (s[i] && s[i] != c)
			i++;
		if (i > start)
		{
			array[index] = allocate_string(s, start, i);
			if (!array[index])
				while (index-- > 0)
					free(array[index]);
			index++;
		}
	}
	array[index] = NULL;
	return (array);
}

char	**ft_split(char const *s, char c)
{
	int		arr_len;
	char	**array;

	if (!s)
		return (NULL);
	arr_len = ft_strs_len(s, c);
	array = malloc((arr_len + 1) * sizeof(char *));
	if (!array)
		return (NULL);
	return (allocate_array(array, s, c));
}
