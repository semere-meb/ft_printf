/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: semebrah <semebrah@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 15:56:25 by semebrah          #+#    #+#             */
/*   Updated: 2025/11/25 15:57:09 by semebrah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*_dest;
	const unsigned char	*_src = src;

	_dest = dest;
	i = 0;
	if (src > dest)
	{
		while (i < n)
		{
			_dest[i] = _src[i];
			i++;
		}
	}
	else if (src < dest)
	{
		while (n-- > 0)
			_dest[n] = _src[n];
	}
	return (dest);
}
