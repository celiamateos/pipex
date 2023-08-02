/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmateos- <cmateos-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 16:26:08 by cmateos-          #+#    #+#             */
/*   Updated: 2023/04/15 14:09:35 by cmateos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_striteri(char *s, void (*f) (unsigned int, char*))
{
	unsigned int	i;

	i = 0;
	while (s[i] != '\0')
	{
		f(i, &s[i]);
		i++;
	}
}
/*
void	funci(unsigned int i, char *c)
{	
	i = 0;
	*c = *c -32;
}

int	main(void)
{
	char	s [100] = "aquilimpiamostaquillas";
	ft_striteri(s, funci);
	printf("%s", s);
	return (0);
}
*/
