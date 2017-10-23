/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpagot <rpagot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 21:59:40 by rpagot            #+#    #+#             */
/*   Updated: 2016/11/18 22:24:53 by rpagot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(char const *big, char const *little)
{
	int		i;
	int		i2;

	i = 0;
	i2 = -1;
	if (!(little[i]))
		return ((char*)big);
	while (big[i])
	{
		if (big[i] == little[0])
			if (!(ft_strcmp(ft_strsub(big, i, ft_strlen(little)),
						little)) && i2 == -1)
				i2 = i;
		++i;
	}
	if (i2 == -1)
		return (NULL);
	return ((char*)(&big[i2]));
}
