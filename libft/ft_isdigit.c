/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmateos- <cmateos-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 18:07:54 by cmateos-          #+#    #+#             */
/*   Updated: 2023/04/12 20:41:04 by cmateos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*Checks if the character passed as a parameter is a number.*/
#include "libft.h"

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}
/*
int main(void)
{
    char c = '4';
    char c2 = 'a';

    printf("%d\n", ft_isdigit(c));
    printf("%d", ft_isdigit(c2));
    return (0);
}*/
