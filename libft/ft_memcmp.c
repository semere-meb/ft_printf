/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: semebrah <semebrah@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 16:05:40 by semebrah          #+#    #+#             */
/*   Updated: 2025/11/25 16:05:57 by semebrah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				i;
	const unsigned char	*_s1;
	const unsigned char	*_s2;

	i = 0;
	_s1 = s1;
	_s2 = s2;
	if (n == 0)
		return (0);
	while (i < n - 1 && _s1[i] == _s2[i])
		i++;
	return (_s1[i] - _s2[i]);
}
