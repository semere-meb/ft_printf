/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: semebrah <semebrah@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 10:10:01 by semebrah          #+#    #+#             */
/*   Updated: 2025/11/27 10:50:31 by semebrah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_ismember(const char c, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

// comment
char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	left;
	size_t	right;

	if (!s1 || !set)
		return (NULL);
	right = ft_strlen(s1);
	if (right == 0)
		return (ft_strdup(s1));
	left = 0;
	right--;
	while (s1[left] && ft_ismember(s1[left], set))
		left++;
	while (right >= left && ft_ismember(s1[right], set))
		right--;
	return (ft_substr(s1, left, right - left + 1));
}
