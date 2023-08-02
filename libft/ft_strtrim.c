/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmateos- <cmateos-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 13:05:15 by cmateos-          #+#    #+#             */
/*   Updated: 2023/04/13 17:46:14 by cmateos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*@brief ALOCA MEMORIA*/
#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*result;
	size_t	i;
	size_t	end;
	size_t	lenresult;

	i = 0;
	result = 0;
	end = ft_strlen(s1);
	if (s1 != NULL && set != NULL)
	{
		while (s1[i] != '\0' && ft_strchr(set, s1[i]))
			i++;
		while (end > i && ft_strchr(set, s1[end]))
			end--;
		lenresult = (end - i + 1);
		result = ft_substr(s1, i, lenresult);
	}
	return (result);
}
/*
int	main(void)
{
	char	s1 [] = "abc42abc";
	char	set [] = "abc";
	char	*result;

	result = ft_strtrim(s1, set);
	printf("%s", result);
	return(0);
}*/
