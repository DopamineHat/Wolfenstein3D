/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpagot <rpagot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 21:32:21 by rpagot            #+#    #+#             */
/*   Updated: 2016/11/18 21:32:24 by rpagot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_count_size(int nb)
{
	int size;

	size = 0;
	if (nb < 0)
	{
		++size;
		nb = -nb;
	}
	while (nb >= 10)
	{
		nb = nb / 10;
		++size;
	}
	return (size);
}

char			*ft_itoa(int n)
{
	char	*l;
	int		i;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	i = ft_count_size(n);
	if ((l = (char*)ft_memalloc((i + 2) * sizeof(char))) == NULL)
		return (NULL);
	l[i + 1] = '\0';
	if (n < 0)
	{
		n = -n;
		l[0] = '-';
	}
	while (i >= 0 && !(l[0] == '-' && i == 0))
	{
		l[i] = (n % 10) + '0';
		n = n / 10;
		--i;
	}
	return (l);
}
