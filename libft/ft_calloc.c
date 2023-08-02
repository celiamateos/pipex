/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmateos- <cmateos-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 17:51:47 by cmateos-          #+#    #+#             */
/*   Updated: 2023/04/12 20:39:10 by cmateos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
 *Reserves a memory space that is filled with zeroes.
 *@count is s the size of the string.
 *@ size is the size of character that form it. */
#include "libft.h"
/*@brief ALOCA MEMORIA*/
void	*ft_calloc(size_t count, size_t size)
{
	void	*p;

	p = malloc(count * size);
	if (!p)
		return (NULL);
	ft_memset(p, 0, (count * size));
	return (p);
}
