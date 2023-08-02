/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmateos- <cmateos-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 20:13:14 by cmateos-          #+#    #+#             */
/*   Updated: 2023/04/12 20:50:13 by cmateos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*@brief ALOCA MEMORIA*/
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*subs;

	if (s == NULL)
		return (NULL);
	if (start > ft_strlen(s))
		len = 0;
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	subs = malloc((len + 1) * sizeof(char));
	if (!subs)
		return (NULL);
	ft_memcpy(subs, &s[start], len);
	subs[len] = '\0';
	return (subs);
}
/*
int	main(void)
{
	char	s [] = "Probando, probando, vamos a crear 42 cajas";
	unsigned int	start = 34;
	size_t	len = 2;
	char	*result;

	result = ft_substr(s, start, len);
	printf ("%s", result);
	return (0);
}*/
