/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_doublefree.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeletan <adeletan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 09:28:44 by adeletan          #+#    #+#             */
/*   Updated: 2017/10/06 04:31:21 by rpagot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_doublefree(char ***s, void (*f) (void *))
{
	size_t	index;

	index = 0;
	if (s == NULL || f == NULL || *s == NULL)
		return ;
	while ((*s)[index])
	{
		f((*s)[index]);
		index++;
	}
	free(*s);
}
