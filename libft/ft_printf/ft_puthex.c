/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmateos- <cmateos-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 20:54:26 by cmateos-          #+#    #+#             */
/*   Updated: 2023/05/24 14:57:12 by cmateos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../libft.h"

int	ft_puthex(unsigned int nbr, char *hex, int *count)
{
	if (nbr / 16 != 0)
		ft_puthex(nbr / 16, hex, count);
	nbr = nbr % 16;
	*count += write (1, &hex[nbr], 1);
	return (0);
}
