/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memnset.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeletan <adeletan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 08:32:30 by adeletan          #+#    #+#             */
/*   Updated: 2016/12/01 08:34:01 by adeletan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memnset(void *b, int c, size_t len, size_t n)
{
	char	*d;
	size_t	index;

	d = b;
	index = n;
	while (len--)
	{
		d[index++] = (unsigned char)c;
	}
	b = d;
	return (b);
}
