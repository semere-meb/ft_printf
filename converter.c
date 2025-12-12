#include "ft_printf.h"

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
	str = malloc((n < 0) + digit_count + 1);
	if (!str)
		return (NULL);
	return (ft_populate(str, _n, (n < 0), (n < 0) + digit_count, base_to));
}
