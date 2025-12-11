/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: semebrah <semebrah@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 13:20:58 by semebrah          #+#    #+#             */
/*   Updated: 2025/11/27 13:25:40 by semebrah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	_n;
	char	c;

	_n = n;
	if (n < 0)
	{
		write(fd, "-", 1);
		_n *= -1;
	}
	if (_n > 9)
		ft_putnbr_fd(_n / 10, fd);
	c = '0' + _n % 10;
	write(fd, &c, 1);
}
