/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeletan <adeletan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 07:01:35 by adeletan          #+#    #+#             */
/*   Updated: 2016/11/24 02:38:27 by adeletan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t index;
	size_t limit;

	index = 0;
	limit = ft_strlen((char*)src);
	while (index < len)
	{
		if (index > limit)
			dst[index] = '\0';
		else
			dst[index] = src[index];
		index++;
	}
	return (dst);
}
