/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmateos- <cmateos-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 16:40:15 by cmateos-          #+#    #+#             */
/*   Updated: 2023/04/10 19:09:47 by cmateos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <fcntl.h>

void	ft_putchar_fd(char c, int fd)
{
	write (fd, &c, 1);
}
/*
int	main(void)
{
	int		fd;
	char	c;
	c = 'Z';
	fd = open("xd_perms", O_CREAT | O_WRONLY, 0777);
	printf("File descriptor asignado: %d\n", fd);
	printf("Ascii de la letra guardada en la variable c:
   	%d\n y la letra es %c\n", c, c);
	ft_putchar_fd(c, fd);
	close(fd);
	return (0);
}*/
