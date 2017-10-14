/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_array.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeletan <adeletan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/04 23:47:06 by adeletan          #+#    #+#             */
/*   Updated: 2016/12/05 03:20:06 by adeletan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_sort_array(char *str)
{
	int		i;
	int		i2;
	int		i3;
	char	*tmp;

	i = 0;
	i2 = -1;
	i3 = 0;
	tmp = ft_strdup(str);
	while (++i2 <= 127)
	{
		i = 0;
		while (str[i])
		{
			if (str[i] == i2)
			{
				tmp[i3] = str[i];
				++i3;
			}
			++i;
		}
	}
	ft_strcpy(str, tmp);
	ft_strdel(&tmp);
}
