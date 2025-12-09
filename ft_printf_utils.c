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

char * ft_append(char *s1, char *s2, size_t size) {
	if (!s1 || !s2)
		return NULL;
	size_t s1_len = ft_strlen(s1);
	char *res = calloc( s1_len + size + 1, sizeof(char));
	if (!res)
		return NULL;

	ft_memcpy(res, s1, s1_len);
	ft_memcpy(res + s1_len, s2, size);
	res[s1_len + size] = '\0';
	return res;
}

ssize_t	ft_index(const char *s, char c)
{
	size_t	i;

	if (!s)
		return (-1);
	i = 0;
	while (s[i] != c)
		if (!s[i++])
			return (-1);
	return (i);
}

static char	*ft_populate(char *str, long n, int is_negative, size_t digit_count,
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
	if (base_len == 2)
		str[digit_count--] = 'b';
	else if (base_len == 8)
		str[digit_count--] = 'o';
	else if (base_len == 16 && base_to[base_len-1] == 'f')
		str[digit_count--] = 'x';
	else if (base_len == 16 && base_to[base_len-1] == 'F')
		str[digit_count--] = 'X';
	str[digit_count] = '0';
	return (str);
}

static size_t	ft_count_digits(long n, size_t base_len)
{
	size_t	digit_count;

	if (n == 0)
		return (1);
	digit_count = 0;
	while (n > 0)
	{
		digit_count++;
		n /= base_len;
	}
	return (digit_count);
}

char	*ft_convert_base(int n, char *base_to)
{
	long	_n;
	char	*str;
	size_t	digit_count;
	size_t	base_len;

	base_len = ft_strlen(base_to);
	_n = n;
	if (_n < 0)
		_n *= -1;
	digit_count = ft_count_digits(_n, base_len);
	str = malloc(2 + (n < 0) + digit_count + 1);
	if (!str)
		return (NULL);
	return (ft_populate(str, _n, 2 + (n < 0), (n < 0) + digit_count, base_to));
}
