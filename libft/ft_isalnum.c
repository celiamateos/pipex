/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmateos- <cmateos-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 18:00:00 by cmateos-          #+#    #+#             */
/*   Updated: 2023/04/12 20:40:05 by cmateos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*Checks if the character passed as a parameter is alphanumeric.*/
#include "libft.h"

int	ft_isalnum(int c)
{
	if (ft_isalpha(c) || ft_isdigit(c))
		return (1);
	return (0);
}
/*
int main(void)
{
    int c = '4';
    int c2 = 'a';
    int c3 = '_';
    int c4 = '{';
    int c5 = 'P';

    printf("%d\n", ft_isalnum(c));
    printf("%d\n", ft_isalnum(c2));
    printf("%d\n", ft_isalnum(c3));
    printf("%d\n", ft_isalnum(c4));
    printf("%d", ft_isalnum(c5));
    return (0);
}*/
