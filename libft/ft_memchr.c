/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmateos- <cmateos-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 15:10:56 by cmateos-          #+#    #+#             */
/*   Updated: 2023/04/12 20:55:52 by cmateos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*This function searches a character(c) in a memory block(*s).
@n is the number of bytes to be searched from the initial location.
@Return a pointer to the first byte where c is found 
or a null pointer if c is not found finds c.
Only searches in one direction, from left to right.*/
#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned const char	*str;
	unsigned char		chr;
	size_t				i;

	str = s;
	chr = c;
	i = 0;
	while (i < n)
	{
		if (str[i] == chr)
			return ((void *)&str[i]);
		i++;
	}
	if (chr == '\0')
		return (NULL);
	return (NULL);
}
/*
int	main(void)
{
	int c = '4';
	const char s [] = "Con 42 cojones";
	char	*result;
	char	*result1;
	size_t	n = 5;
	result = ft_memchr(s, c, n);
	result1 = memchr(s, c, n);
	printf("ft_memchr: %s\n", result);
	printf("memchr: %s", result1);
	return (0);
}*/
