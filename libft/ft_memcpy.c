/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: semebrah <semebrah@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 15:57:28 by semebrah          #+#    #+#             */
/*   Updated: 2025/11/25 15:57:40 by semebrah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*_dest;
	const unsigned char	*_src = src;

	i = 0;
	_dest = dest;
	while (i < n)
	{
		_dest[i] = _src[i];
		i++;
	}
	return (dest);
}
