/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmateos- <cmateos-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 20:04:23 by cmateos-          #+#    #+#             */
/*   Updated: 2023/04/17 20:06:12 by cmateos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*@brief ALOCA MEMORIA*/
#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*node;

	node = (t_list *)malloc(sizeof (t_list));
	if (node == NULL)
		return (NULL);
	node->content = content;
	node->next = NULL;
	return (node);
}
/*
int	main(void)
{
	int		content;
	t_list	*result;

	content = 42;
	result = ft_lsnew(content);
	printf("%s", result);
	return (0);
}*/
