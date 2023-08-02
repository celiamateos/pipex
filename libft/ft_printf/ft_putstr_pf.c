/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_pf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmateos- <cmateos-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 14:06:34 by cmateos-          #+#    #+#             */
/*   Updated: 2023/05/24 14:59:22 by cmateos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_putstr_pf(char *s)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	if (s == NULL)
	count += (ft_putstr_pf("(null)"));
	if (s)
	{
		while (s[i] != '\0')
		{
			count += write(1, &s[i], 1);
			i++;
		}
	}
	return (count);
}
