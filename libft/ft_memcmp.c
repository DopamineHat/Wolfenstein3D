/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeletan <adeletan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 20:15:06 by adeletan          #+#    #+#             */
/*   Updated: 2016/11/24 02:31:31 by adeletan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*copy1;
	unsigned char	*copy2;
	size_t			index;

	copy1 = (unsigned char*)s1;
	copy2 = (unsigned char*)s2;
	if (s1 == s2)
		return (0);
	index = 0;
	while (n--)
	{
		if (copy1[index] != copy2[index])
			return (copy1[index] - copy2[index]);
		++index;
	}
	return (0);
}
