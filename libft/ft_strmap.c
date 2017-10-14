/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeletan <adeletan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 07:35:55 by adeletan          #+#    #+#             */
/*   Updated: 2016/11/24 02:37:44 by adeletan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f) (char))
{
	size_t	index;
	char	*array;

	if (s == NULL)
		return (NULL);
	index = ft_strlen(s);
	if (!(array = (char*)malloc((index + 1) * sizeof(char))))
		return (NULL);
	index = 0;
	while (s[index])
	{
		array[index] = f(s[index]);
		++index;
	}
	array[index] = '\0';
	return (array);
}
