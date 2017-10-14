/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeletan <adeletan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 23:24:23 by adeletan          #+#    #+#             */
/*   Updated: 2016/11/24 02:30:02 by adeletan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del) (void *, size_t))
{
	t_list *tmp;
	t_list *lst;

	lst = *alst;
	if (!alst || !del)
		return ;
	while (lst)
	{
		del(lst->content, lst->content_size);
		tmp = lst->next;
		free(lst);
		lst = tmp;
	}
	*alst = NULL;
}
