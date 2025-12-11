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
#include <stdarg.h>
#include <stdio.h>

void	ft_printf(const char *f, ...)
{
	va_list args;
	size_t i = 0;
	t_template *tpl = malloc(sizeof(t_template));
	if (!tpl)
		return;

	va_start(args, f);

	while(f[i]){



	}
	va_end(args);

	write(1, &f[i], ft_strlen(&f[i]));

}

int	main(void)
{
	ft_printf("hello %s, today is %d centigrade, a 10");
}
