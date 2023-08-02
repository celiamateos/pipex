/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmateos- <cmateos-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 22:22:47 by cmateos-          #+#    #+#             */
/*   Updated: 2023/04/12 20:34:46 by cmateos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/* This function set 0 or NULL n number of character.
 * If I print el character 3(space), print a letter 'q', dont worry, its ok''*/
#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while ((i < n) && (n != 0))
	{
		((unsigned char *)s)[i] = 0;
		i++;
	}
}
/*
int	main(void)
{
	unsigned char	s [] = "No quiero vivir";
	size_t	n = 2;
	ft_bzero(s, n);
	printf("%c", s[0]);
	return (0);
}*/
