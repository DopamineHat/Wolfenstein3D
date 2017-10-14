/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeletan <adeletan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 07:23:49 by adeletan          #+#    #+#             */
/*   Updated: 2016/11/24 02:36:33 by adeletan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strequ(char const *s1, char const *s2)
{
	size_t	index;

	if (s1 == NULL || s2 == NULL)
		return (0);
	index = 0;
	while (s1[index] || s2[index])
	{
		if (s1[index] != s2[index])
			return (0);
		++index;
	}
	return (1);
}
