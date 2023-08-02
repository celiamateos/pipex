/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmateos- <cmateos-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 15:31:16 by cmateos-          #+#    #+#             */
/*   Updated: 2023/06/30 15:31:18 by cmateos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*@brief ALOCA MEMORIA
@brief NO PASA EL PACO*/
#include "libft.h"

t_list *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
    t_list  *result;
    t_list  *temp;

    if (!lst || !f || !del)
        return (NULL);
    while (lst->next != NULL)
    {
        temp = lst->next;
        result = ft_lstnew(f(lst->content));
        ft_lstdelone(lst, del);
        if (!result)
            ft_lstdelone(result, del);
        lst = temp;
    }
    return (lst);
}