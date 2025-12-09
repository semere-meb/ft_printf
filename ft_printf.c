/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: semebrah <semebrah@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 17:23:48 by semebrah          #+#    #+#             */
/*   Updated: 2025/12/09 17:24:06 by semebrah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf(const char *f, ...)
{
	va_list args;

	ssize_t ix;
	char *temp;

	va_start(args, f);

	while(ft_index(f, '%') > -1){
		ix = ft_index(f, '%');
		write(1, f, ix);
		f = &f[ix];
		
		if (*f == 'c')
			temp = (char []){va_arg(args, int)};
		else if (*f == 's')
			temp = va_arg(args, char*);
		else if (*f == 'p')
			temp = ft_convert_base(va_arg(args, unsigned int), "012345679abcdef");
		else if (*f == 'd' || *f == 'i')
			temp = ft_convert_base(va_arg(args, int), "012345679");
		else if (*f == 'u')
			temp = ft_convert_base(va_arg(args, unsigned int), "012345679");
		else if (*f == 'x')
			temp = ft_convert_base(va_arg(args, int), "012345679abcdef");
		else if (*f == 'X')
			temp = ft_convert_base(va_arg(args, int), "012345679ABCDEF");
		else if (*f == '%')
			temp = (char []){va_arg(args, int)};

		write(1, temp, ft_strlen(temp));
	}

	write(1, f, ft_strlen(f));

	va_end(args);
}

// int	main(void)
// {
// 	ft_printf("hello %s, today is %d centigrade, a 10%%", "semere", 24);
// 	// printf("hello %s, today is %d centigrade, a 10%%", "semere", 24);
// }
