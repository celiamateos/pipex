/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmateos <cmateos-@student.42madrid.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 17:43:07 by cmateos           #+#    #+#             */
/*   Updated: 2023/06/28 19:07:46 by cmateos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!del)
		return ;
	if (lst)
		del(lst->content);
	free(lst);
}
/*
void	del(void *p);
{
	free (
}

int	main(void)
{
	void *p;

	p = NULL;
	int	content;
	t_list *result;

	content = 42;
	result = (ft_lstdelone(lst(del(p));
	printf("%i", result);
}*/
