/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeletan <adeletan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 20:48:20 by adeletan          #+#    #+#             */
/*   Updated: 2016/11/24 02:37:21 by adeletan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t i;
	size_t index;
	size_t index2;

	index = ft_strlen(dst);
	index2 = ft_strlen(src);
	i = 0;
	if (size == 0)
		return (index2 + size);
	while (src[i] != '\0' && ((index + i) < (size - 1)))
	{
		dst[index + i] = src[i];
		i++;
	}
	dst[index + i] = '\0';
	if (index < size)
		return (index2 + index);
	else
		return (index2 + size);
}
