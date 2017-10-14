/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpagot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 05:29:50 by rpagot            #+#    #+#             */
/*   Updated: 2016/11/24 02:38:08 by adeletan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, char const *s2, size_t n)
{
	size_t index;
	size_t limit;
	size_t index2;

	index = ft_strlen(s1);
	index2 = 0;
	limit = ft_strlen((char*)s2);
	if (n > limit)
		n = limit;
	while (index2 < n)
	{
		if (index2 < limit)
			s1[index] = s2[index2];
		else
			s1[index] = '\0';
		++index2;
		++index;
		if (n == limit && !(index2 < n))
			s1[index] = '\0';
		if (n)
		{
			s1[index] = '\0';
		}
	}
	return (s1);
}
