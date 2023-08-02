/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmateos- <cmateos-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 18:05:27 by cmateos-          #+#    #+#             */
/*   Updated: 2023/03/22 19:40:09 by cmateos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_isascii(int c)
{
	return (c >= 0 && c <= 127);
}
/*
int main(void)
{
    char c = '4';
    char c2 = 'a';
    char c3 = '_';
    char c4 = '{';
    char c5 = ' ';
    char c6 = -1;

    printf("%d\n", ft_isascii(c));
    printf("%d\n", ft_isascii(c2));
    printf("%d\n", ft_isascii(c3));
    printf("%d\n", ft_isascii(c4));
    printf("%d\n", ft_isascii(c5));
    printf("%d", ft_isascii(c6));
    return (0);
}*/
