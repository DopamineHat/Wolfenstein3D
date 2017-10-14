/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeletan <adeletan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 19:23:29 by adeletan          #+#    #+#             */
/*   Updated: 2016/11/24 02:31:52 by adeletan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
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
		++index;
	}
	dst = patate;
	return (dst);
}
