/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeletan <adeletan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 00:35:25 by adeletan          #+#    #+#             */
/*   Updated: 2016/11/24 02:29:51 by adeletan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_count_size(int nb)
{
	int size;

	size = 1;
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
	char	*array;
	size_t	index;
	int		negative;

	negative = 0;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	index = ft_count_size(n);
	if ((array = (char*)malloc((index + 1) * sizeof(char))) == NULL)
		return (NULL);
	array[index] = '\0';
	if (n < 0)
	{
		n = -n;
		negative = 1;
	}
	while (index != 0)
	{
		array[--index] = (n % 10) + '0';
		n = n / 10;
	}
	if (negative == 1)
		array[0] = '-';
	return (array);
}
