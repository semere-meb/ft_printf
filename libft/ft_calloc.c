/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: semebrah <semebrah@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 17:26:37 by semebrah          #+#    #+#             */
/*   Updated: 2025/11/27 13:03:17 by semebrah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*res;
	size_t	s;

	s = nmemb * size;
	if (s > 0 && s / nmemb != size)
		return (NULL);
	res = malloc(s);
	if (!res)
		return (NULL);
	ft_bzero(res, s);
	return (res);
}
