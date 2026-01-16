/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: semebrah <semebrah@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 19:36:46 by semebrah          #+#    #+#             */
/*   Updated: 2025/12/15 19:37:33 by semebrah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	ft_count_digits(unsigned long long n, size_t base_len)
{
	size_t	digit_count;

	if (n == 0)
		return (1);
	digit_count = 0;
	while (n > 0)
	{
		digit_count++;
		n = n / (long long)base_len;
	}
	return (digit_count);
}

char	*convert(unsigned long long n, char *base_to)
{
	char	*str;
	size_t	digit_count;
	size_t	base_len;

	if (n == 0)
		return (ft_strdup("0"));
	base_len = ft_strlen(base_to);
	digit_count = ft_count_digits(n, base_len);
	str = malloc(digit_count + 1);
	if (!str)
		return (NULL);
	str[digit_count--] = '\0';
	while (n > 0)
	{
		str[digit_count--] = base_to[n % base_len];
		n /= base_len;
	}
	return (str);
}
