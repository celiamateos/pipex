/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmateos- <cmateos-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 19:35:01 by cmateos-          #+#    #+#             */
/*   Updated: 2023/04/12 18:32:39 by cmateos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	if (n < 0)
	{
		n = n * (-1);
		write (fd, "-", 1);
	}
	if (n == -2147483648)
	{
		write (fd, "2147483648", 10);
	}
	else
	{
		if (n < 10)
		{
			n = n + '0';
			write (fd, &n, 1);
		}
		else
		{
			ft_putnbr_fd(n / 10, fd);
			n = n % 10 + '0';
			write (fd, &n, 1);
		}
	}
}
/*
int	main(void)
{
	int	n;
	int	fd;

	fd = 0;
	n = -2147483648;
	ft_putnbr_fd(n, fd);
	return (0);
}*/
