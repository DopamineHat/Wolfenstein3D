/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap_universal.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpagot <rpagot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/20 02:45:20 by rpagot            #+#    #+#             */
/*   Updated: 2016/11/20 03:51:07 by rpagot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_swap_universal(void *a, void *b, size_t n)
{
	unsigned char tmp;

	while (n-- > 0 && a && b)
	{
		tmp = *(unsigned char *)a;
		*(unsigned char *)a = *(unsigned char *)b;
		*(unsigned char *)b = tmp;
		++a;
		++b;
	}
}
