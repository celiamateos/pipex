/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmateos- <cmateos-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 18:17:08 by cmateos-          #+#    #+#             */
/*   Updated: 2023/04/12 20:21:31 by cmateos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include"string.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (s1[i] == '\0' && s2[i] == '\0')
		return (0);
	if (!s2 || !n)
		return (0);
	while ((s1[i] != '\0' || s2[i] != '\0') && (((i + 1) < n)))
	{
		if (s1[i] == s2[i])
			i++;
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
/*
int main(void)
{
	const char	s1 [] = "aana vez tuve un sueño y se hizo realidad";
	const char	s2 [] = "aaKIEN DIJO SUERTE?";
	size_t		n = 3;
	printf("ft_strncmp: %d\n", ft_strncmp(s1, s2, n));
	printf("strncmp: %d", strncmp(s1, s2, n));
	return (0);
}*/
