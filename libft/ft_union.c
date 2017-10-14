/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_union.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeletan <adeletan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 09:01:32 by adeletan          #+#    #+#             */
/*   Updated: 2016/12/06 10:31:48 by adeletan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_union(char **argv)
{
	char	*str;
	size_t	index;
	size_t	index2;
	size_t	index3;

	index = 0;
	str = ft_strnew(0);
	while (argv[++index] && argv[index][0] == '-')
	{
		index2 = 0;
		while (argv[index][++index2] && (index3 = -1))
			while (str[++index3] || str[0] == '\0')
				if (str[index3] == argv[index][index2])
					break ;
				else if (str[0] == '\0' && (str[0] = argv[index][index2]))
					break ;
				else if (!str[index3 + 1])
				{
					str = ft_realloc(str, index3 + 1);
					str[index3 + 1] = argv[index][index2];
					str[index3 + 2] = '\0';
					break ;
				}
	}
	return (str);
}
