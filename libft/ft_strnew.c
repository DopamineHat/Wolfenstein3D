/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpagot <rpagot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 21:51:32 by rpagot            #+#    #+#             */
/*   Updated: 2017/05/10 10:59:24 by rolemass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*array;
	size_t	i;

	i = 0;
	if (!(array = (char*)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	array[size] = '\0';
	while (i < size)
	{
		array[i] = '\0';
		++i;
	}
	return (array);
}
