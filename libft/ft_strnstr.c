/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeletan <adeletan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 05:23:06 by adeletan          #+#    #+#             */
/*   Updated: 2016/11/26 03:40:56 by adeletan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(char const *big, char const *little, size_t len)
{
	size_t	index;
	size_t	index2;
	size_t	poubelle;

	if (len > (unsigned long)ft_strlen(little))
		poubelle = (unsigned long)ft_strlen(little);
	else
		poubelle = len;
	index = 0;
	index2 = -1;
	if (!(little[index]))
		return ((char*)big);
	while (big[index] && (index + ft_strlen(little) <= len))
	{
		if (big[index] == little[0])
			if (!(ft_strcmp(ft_strsub(big, index, poubelle),
				ft_strsub(little, 0, poubelle))) && index2 == (size_t)-1)
				index2 = index;
		++index;
	}
	if (index2 == (size_t)-1)
		return (NULL);
	return ((char*)(&big[index2]));
}
