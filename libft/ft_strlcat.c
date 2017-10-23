/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpagot <rpagot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 21:48:12 by rpagot            #+#    #+#             */
/*   Updated: 2016/11/18 21:48:15 by rpagot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t n)
{
	size_t i;
	size_t l1;
	size_t l2;

	i = 0;
	l1 = ft_strlen(dst);
	l2 = ft_strlen(src);
	if (n < l1)
		return (n + l2);
	while (*src && (l1 + i + 1) < n)
	{
		dst[l1 + i] = src[i];
		++i;
	}
	dst[l1 + i] = '\0';
	return (l1 + l2);
}
