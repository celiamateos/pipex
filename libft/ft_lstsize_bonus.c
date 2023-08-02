/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmateos <cmateos-@student.42madrid.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 17:18:55 by cmateos           #+#    #+#             */
/*   Updated: 2023/06/28 17:32:22 by cmateos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		i;
	t_list	*temp;

	temp = lst;
	i = 0;
	if (temp)
	{
		while (temp->next != NULL)
		{
			temp = temp->next;
			i++;
		}
		if (temp->next == NULL)
			i++;
	}
	return (i);
}
