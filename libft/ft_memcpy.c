/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmateos- <cmateos-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 23:53:56 by cmateos-          #+#    #+#             */
/*   Updated: 2023/04/13 17:47:29 by cmateos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*destination;
	unsigned const char	*source;
	size_t				i;

	destination = dst;
	source = src;
	i = 0;
	if (dst || src)
	{
		while (i < n)
		{
			destination[i] = source[i];
			i++;
		}
	}
	return (dst);
}
/*
int	main(void)
{
	char	dst [] = "Mundo";
	char	src [] = "Hola";
	size_t	n = 3;
	char	*result;

	result = ft_memcpy(dst, src, n);
	printf("%s\n", result);
	printf("%s", memcpy(dst, src, n));
	return (0);
}*/
