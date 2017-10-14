/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnarray.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeletan <adeletan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 04:55:37 by adeletan          #+#    #+#             */
/*   Updated: 2016/11/24 02:33:20 by adeletan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnarray(char **array, size_t end)
{
	size_t start;

	start = 0;
	while (start <= end)
	{
		ft_putendl(array[start]);
		++start;
	}
}
