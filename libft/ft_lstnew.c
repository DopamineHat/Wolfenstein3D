/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpagot <rpagot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 17:16:50 by rpagot            #+#    #+#             */
/*   Updated: 2016/11/18 21:34:44 by rpagot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*list;
	void	*content2;

	content2 = NULL;
	if ((content2 = malloc(content_size + 1)) == NULL)
		return (NULL);
	if (content)
		ft_memcpy(content2, content, content_size);
	else
	{
		content2 = NULL;
		content_size = 0;
	}
	if ((list = (t_list *)malloc(sizeof(t_list))) == NULL)
		return (NULL);
	list->content = content2;
	list->content_size = content_size;
	list->next = NULL;
	return (list);
}
