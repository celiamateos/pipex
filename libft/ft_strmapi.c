/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmateos- <cmateos-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 16:48:25 by cmateos-          #+#    #+#             */
/*   Updated: 2023/04/10 18:52:49 by cmateos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*@brief ALOCA MEMORIA*/
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*result;
	size_t			len;
	unsigned int	i;

	i = 0;
	len = ft_strlen(s);
	result = malloc((len + 1) * sizeof(char));
	if (!result)
		return (NULL);
	while (i < len)
	{
		result[i] = f(i, s[i]);
		i++;
	}
	result[i] = '\0';
	return (result);
}
/*
char	funcion(unsigned int i, char c)
{	
	i = 0;
	return (c - 32);
}
int	main(void)
{
	char	s [] = "aquiquemamostaquillasytedamosunaslimpias";
	printf("%s", ft_strmapi(s, funcion));
	return (0);
}*/
