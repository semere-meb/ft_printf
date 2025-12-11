/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: semebrah <semebrah@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 11:30:42 by semebrah          #+#    #+#             */
/*   Updated: 2025/11/27 12:27:50 by semebrah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_assign_str(char *str, long n, int is_negative,
		size_t digit_count)
{
	str[digit_count--] = '\0';
	while (n > 0)
	{
		str[digit_count--] = '0' + n % 10;
		n /= 10;
	}
	if (is_negative)
		str[digit_count] = '-';
	return (str);
}

static size_t	ft_count_digits(long n)
{
	size_t	digit_count;

	digit_count = 0;
	while (n > 0)
	{
		digit_count++;
		n /= 10;
	}
	return (digit_count);
}

char	*ft_itoa(int n)
{
	long	_n;
	char	*str;
	size_t	digit_count;

	if (n == 0)
		return (ft_strdup("0"));
	_n = n;
	if (_n < 0)
		_n *= -1;
	digit_count = ft_count_digits(_n);
	str = malloc((n < 0) + digit_count + 1);
	if (!str)
		return (NULL);
	return (ft_assign_str(str, _n, (n < 0), (n < 0) + digit_count));
}
