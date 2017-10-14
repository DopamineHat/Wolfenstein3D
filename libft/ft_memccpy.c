/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeletan <adeletan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 19:23:29 by adeletan          #+#    #+#             */
/*   Updated: 2016/11/24 02:30:53 by adeletan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*patate;
	unsigned char	*carotte;
	size_t			index;

	patate = (unsigned char*)dst;
	carotte = (unsigned char*)src;
	index = 0;
	while (n--)
	{
		patate[index] = carotte[index];
		if (patate[index] == (unsigned char)c)
			return (&patate[index + 1]);
		++index;
	}
	dst = patate;
	return (NULL);
}
