/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy_bwd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeletan <adeletan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 19:59:52 by adeletan          #+#    #+#             */
/*   Updated: 2016/12/06 05:13:51 by adeletan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy_bwd(void *dst, const void *src, size_t len)
{
	char	*s1;
	char	*s2;

	if (len == 0 || dst == src)
		return (dst);
	s1 = (char*)dst;
	s2 = (char*)src;
	while (len--)
		s1[len] = s2[len];
	return (dst);
}
