/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpagot <rpagot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 21:48:44 by rpagot            #+#    #+#             */
/*   Updated: 2016/11/18 21:48:46 by rpagot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f) (char))
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
		array[i] = f(s[i]);
		++i;
	}
	return (array);
}
