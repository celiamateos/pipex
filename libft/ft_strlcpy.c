/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmateos- <cmateos-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 13:08:09 by cmateos-          #+#    #+#             */
/*   Updated: 2023/04/06 19:04:13 by cmateos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <string.h>

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (dstsize != 0)
	{
		while (src[i] != '\0' && i < (dstsize - 1))
		{
			dst[i] = src[i];
			i++;
		}
	dst[i] = '\0';
	}
	return (ft_strlen(src));
}
/*
int	main(void)
{
	char	src [] = "Hola";
	char	dst [] = "Mundo";
	size_t	dstsize = 12;

	printf("%zu || %s\n", ft_strlcpy(dst, src, dstsize), dst);
	printf("%lu || %s", strlcpy(dst, src, dstsize), dst);
	return(0);
}*/
