/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeletan <adeletan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 07:25:11 by adeletan          #+#    #+#             */
/*   Updated: 2016/11/24 02:38:02 by adeletan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f) (unsigned int, char))
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
		array[index] = f(index, s[index]);
		++index;
	}
	array[index] = '\0';
	return (array);
}
