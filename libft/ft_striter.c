/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeletan <adeletan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 07:52:14 by adeletan          #+#    #+#             */
/*   Updated: 2016/11/24 02:36:51 by adeletan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striter(char *s, void (*f) (char *))
{
	size_t	index;

	index = 0;
	if (s == NULL || f == NULL)
		return ;
	while (s[index])
	{
		f(&s[index]);
		index++;
	}
}
