/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmateos- <cmateos-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 18:32:35 by cmateos-          #+#    #+#             */
/*   Updated: 2023/04/19 19:20:06 by cmateos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*Allocate enough memory to make a copy of s1 returns a pointer to it.*/
/*@brief ALOCA MEMORIA*/
#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*p;

	p = malloc((ft_strlen(s1) + 1) * sizeof(char));
	if (p == NULL)
		exit (1);
	ft_strlcpy(p, s1, ft_strlen(s1) + 1);
	return (p);
}
/*
int	main(void)
{
	char	s1 [] = "Hola k pasa cara pasa!";
	char	*result;
	char	*result1;

	result = ft_strdup(s1);
	result1 = strdup(s1);

	printf("ft_strdup: %s\n", result);
	printf("strdup: %s", result1);
}*/
