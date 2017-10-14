/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeletan <adeletan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 23:46:04 by adeletan          #+#    #+#             */
/*   Updated: 2016/11/24 02:30:21 by adeletan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f) (t_list *elem))
{
	t_list *result;
	t_list *temp;
	t_list *temp2;

	if (!lst || !f)
		return (NULL);
	temp2 = f(lst);
	if ((result = ft_lstnew(temp2->content, temp2->content_size)))
	{
		temp = result;
		lst = lst->next;
		while (lst)
		{
			temp2 = f(lst);
			if (!(temp->next = ft_lstnew(temp2->content, temp2->content_size)))
				return (NULL);
			temp = temp->next;
			lst = lst->next;
		}
	}
	return (result);
}
