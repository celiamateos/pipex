/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmateos- <cmateos-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 19:40:11 by cmateos-          #+#    #+#             */
/*   Updated: 2023/03/29 19:35:06 by cmateos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <string.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	if (needle[j] == '\0')
		return ((char *)haystack);
	while (haystack[i] != '\0')
	{
		while (((i + j) < len) && (haystack[i + j] == needle[j])
			&& needle[j] != '\0')
			j++;
		if (needle[j] == '\0')
			return ((char *)&haystack[i]);
		i++;
		j = 0;
	}
	return (0);
}
/*
int	main (void)
{
	char	elpajar [] = "Estoy un poco obsesionada con el número 42, no?;
	char	laaguja [] = "s";
	printf("%s", strnstr(elpajar, laaguja, 3));
	return (0);
}
*/
