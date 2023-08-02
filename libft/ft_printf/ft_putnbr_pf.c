/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_pf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmateos- <cmateos-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 16:16:38 by cmateos-          #+#    #+#             */
/*   Updated: 2023/05/24 14:57:50 by cmateos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../libft.h"

int	ft_putnbr_pf(long nbr, int *count)
{
	if (nbr < 0)
	{
		*count += ft_putchr_pf('-');
		nbr = nbr * (-1);
	}
	if (nbr / 10 != 0)
		ft_putnbr_pf(nbr / 10, count);
	*count += ft_putchr_pf((nbr % 10) + '0');
	return (0);
}
