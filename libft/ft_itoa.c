/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmateos- <cmateos-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 16:07:56 by cmateos-          #+#    #+#             */
/*   Updated: 2023/04/12 20:42:50 by cmateos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*Returns a memory space where the integer converted to character is stored.*/
#include "libft.h"

static int	ft_lennum(int n)
{
	int	digit;

	digit = 0;
	if (n < 0)
		digit++;
	while (n > 9 || n < -9)
	{
		n = n / 10;
		digit++;
	}
	digit++;
	return (digit);
}
/*
@brief ALOCA MEMORIA
@param n el numero a convertir en string
*/

char	*ft_itoa(int n)
{
	char	*trans;
	int		i;
	int		is_neg;

	is_neg = 0;
	if (n < 0)
		is_neg++;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	i = ft_lennum(n);
	trans = (char *)malloc((i + 1) * sizeof(char));
	if (!trans)
		return (NULL);
	trans[i] = '\0';
	if (n < 0)
		n = n * (-1);
	while (i > 0)
	{
		i--;
		trans[i] = (n % 10) + '0';
		n = n / 10;
	}
	if (is_neg == 1)
		trans[0] = '-';
	return (trans);
}
/*
int	main(void)
{
	int	n;
	n = -1;	
	printf("LENNUM: %i\n", ft_lennum(n));
	printf("STRLEN: %zu\n", ft_strlen(ft_itoa(n)));
	printf("TRANS: %s", ft_itoa(n));

	return (0);
}*/
