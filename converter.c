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

static char	*ft_populate(char *str, long long n, int is_negative, size_t digit_count,
		char *base_to)
{
	size_t	base_len;

	base_len = ft_strlen(base_to);
	str[digit_count--] = '\0';
	while (n > 0)
	{
		str[digit_count--] = base_to[n % base_len];
		n /= base_len;
	}
	if (is_negative)
		str[digit_count--] = '-';
	return (str);
}

static size_t	ft_count_digits(long long n, size_t base_len)
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

char	*base(long long n, char *base_to)
{
	long long	positive_n;
	char	*str;
	size_t	digit_count;
	size_t	base_len;

	if (n == 0)
		return ft_strdup("0");
	base_len = ft_strlen(base_to);
	positive_n = n;
	if (positive_n < 0)
		positive_n = -positive_n;
	digit_count = ft_count_digits(positive_n, base_len);
	str = malloc((n < 0) + digit_count + 1);
	if (!str)
		return (NULL);
	return (ft_populate(str, positive_n, (n < 0), (n < 0) + digit_count, base_to));
}
