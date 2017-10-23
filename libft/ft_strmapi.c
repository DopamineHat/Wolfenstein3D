/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpagot <rpagot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 21:49:21 by rpagot            #+#    #+#             */
/*   Updated: 2016/11/18 21:49:23 by rpagot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f) (unsigned int, char))
{
	int		i;
	char	*array;

	i = 0;
	if (!(s) || !(f))
		return (NULL);
	while (s[i])
		++i;
	if (!(array = (char*)malloc((i + 1) * sizeof(char))))
		return (NULL);
	array[i] = '\0';
	i = 0;
	while (s[i])
	{
		array[i] = f(i, s[i]);
		++i;
	}
	return (array);
}
