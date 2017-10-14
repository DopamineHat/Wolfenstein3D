/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeletan <adeletan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 20:40:24 by adeletan          #+#    #+#             */
/*   Updated: 2016/11/24 02:42:01 by adeletan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	index;
	size_t	index2;

	index = 0;
	index2 = -1;
	while (s[index])
	{
		if (s[index] == (char)c)
			index2 = index;
		++index;
	}
	if (s[index] == (char)c)
		index2 = index;
	else if ((s[index] != (char)c) && (index2 == (size_t)-1))
		return (NULL);
	return ((char*)&s[index2]);
}
