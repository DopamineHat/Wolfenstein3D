/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeletan <adeletan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 19:08:01 by adeletan          #+#    #+#             */
/*   Updated: 2016/11/24 02:32:41 by adeletan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	char	*d;
	size_t	index;

	d = b;
	index = 0;
	while (len--)
	{
		d[index++] = (unsigned char)c;
	}
	b = d;
	return (b);
}
