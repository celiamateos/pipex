/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmateos- <cmateos-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 17:52:20 by cmateos-          #+#    #+#             */
/*   Updated: 2023/04/12 21:04:56 by cmateos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	id;
	size_t	is;
	size_t	len;

	len = ft_strlen(dst);
	id = 0;
	is = 0;
	while (dst[id] != '\0')
			id++;
	if (dstsize != 0 && dstsize >= len)
	{
		while (src[is] && is + 1 < dstsize - len)
		{
			dst[id] = src[is];
			id++;
			is++;
		}
		dst[id] = '\0';
		return (len + ft_strlen(src));
	}	
	else
		return (dstsize + ft_strlen(src));
}
/*
int	main(void)
{
	char	src [] = "Paco";
	char	dst [8] = "hola";
	size_t	dstsize = 7;

	char	src1 [] = "Paco";
	char	dst1 [8] = "hola";
	size_t	dstsize1 = 7;

	printf("%zu || %s\n", ft_strlcat(dst, src, dstsize), dst);
	printf("%lu || %s", strlcat(dst1, src1, dstsize1), dst1);
	return(0);
}**/
