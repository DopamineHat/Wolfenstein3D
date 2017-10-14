/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsetnew.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeletan <adeletan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 06:54:34 by adeletan          #+#    #+#             */
/*   Updated: 2016/12/01 07:48:08 by adeletan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsetnew(size_t size, int c)
{
	char	*array;
	size_t	index;

	index = 0;
	if (!(array = (char*)malloc(size + 1 * sizeof(char))))
		return (NULL);
	array[size + 1] = '\0';
	while (index <= size)
	{
		array[index] = c;
		++index;
	}
	return (array);
}
