/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gloggins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 10:58:06 by gloggins          #+#    #+#             */
/*   Updated: 2019/11/21 11:37:15 by gloggins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*tmp;
	t_list	*lstnew;
	t_list	*res;

	lstnew = NULL;
	while (lst)
	{
		tmp = f(lst);
		if (!lstnew)
		{
			lstnew = tmp;
			res = lstnew;
			lstnew->next = NULL;
		}
		else
		{
			lstnew->next = tmp;
			tmp->next = NULL;
			lstnew = lstnew->next;
		}
		lst = lst->next;
	}
	return (res);
}
