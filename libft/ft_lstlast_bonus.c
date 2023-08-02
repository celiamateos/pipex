/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmateos <cmateos-@student.42madrid.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 17:32:35 by cmateos           #+#    #+#             */
/*   Updated: 2023/06/28 17:39:11 by cmateos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*lastnode;

	lastnode = lst;
	if (lastnode)
	{
		while (lastnode->next != NULL)
			lastnode = lastnode->next;
	}
	return (lastnode);
}
