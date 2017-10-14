/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeletan <adeletan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 07:09:47 by adeletan          #+#    #+#             */
/*   Updated: 2016/11/24 02:40:38 by adeletan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t	index;
	char	*array;

	if (s == NULL)
		return (NULL);
	index = 0;
	if (!(array = (char*)malloc(len + 1 * sizeof(char))))
		return (NULL);
	while (len > 0)
	{
		array[index++] = s[start++];
		--len;
	}
	array[index] = '\0';
	return (array);
}
