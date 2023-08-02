/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmateos- <cmateos-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 18:08:24 by cmateos-          #+#    #+#             */
/*   Updated: 2023/04/12 21:07:45 by cmateos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*Searches for the LAST occurrence of the character c in the string s*/
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = ft_strlen(s);
	while (i >= 0)
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i--;
	}
	return (NULL);
}
/*
int	main(void)
{
	int c = 'm';
	const char s [] = "Por votación democrática ganó el nombre mis cojones 42";
	char *result;
	char *result1;

	result = ft_strrchr(s, c);
	result1 = strrchr(s, c);
	printf("ft_strrchr: %s\n", result);
	printf("strrchr: %s", result1);
	return (0);
}*/
