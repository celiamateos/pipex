/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmateos- <cmateos-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 10:35:54 by cmateos-          #+#    #+#             */
/*   Updated: 2023/04/05 12:33:32 by cmateos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*d;
	unsigned const char	*s;

	d = dst;
	s = src;
	if (dst > src)
	{
		while (len > 0)
		{
			d[len - 1] = s[len - 1];
			len--;
		}
		return (dst);
	}
	if (dst <= src)
		return (ft_memcpy(dst, src, len));
	return (dst);
}
/*
int	main(void)
{
	char	dst [] = "a";
	char	src [] = "12345";
	size_t	len = 3;
	char	*result;

	result = ft_memmove(dst, src, len);
	printf("%s\n", result);
	printf("%s", memmove(dst, src, len));
	return (0);
}*/
//Sería lo mismo poner
//while (len-- > 0)
//d[len] = s[len]
//La diferencia con memcpy
//es que memmove no copia, 
//si no que mueve la memoria
//por lo que si el dst está
//en una posición de memoria
//mayor que el src,
//mueve de derecha a izquierda
//para evitar problemas. RTFM!
