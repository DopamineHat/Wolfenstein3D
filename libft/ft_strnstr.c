/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpagot <rpagot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 21:52:04 by rpagot            #+#    #+#             */
/*   Updated: 2016/12/03 22:43:07 by rpagot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(char const *big, char const *little, size_t len)
{
	size_t	i;

	if (!(*little))
		return ((char*)big);
	i = 0;
	while (*big && len)
	{
		if (*big == little[i])
			++i;
		else
		{
			big -= i;
			len += i;
			i = 0;
		}
		if ((!little[i]))
			return ((char*)(big - i + 1));
		++big;
		--len;
	}
	return (NULL);
}
