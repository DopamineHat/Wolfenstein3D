/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_doubledup.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeletan <adeletan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 02:04:54 by adeletan          #+#    #+#             */
/*   Updated: 2016/12/05 03:11:35 by adeletan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_doubledup(char **tab)
{
	char	**copy;
	int		index;
	int		index2;

	index = 0;
	index2 = 0;
	while (tab[index])
		++index;
	if (!(copy = (char**)malloc(sizeof(char*) * (index + 1))))
		return (NULL);
	index = 0;
	while (tab[index])
	{
		copy[index] = ft_strdup(tab[index]);
		++index;
	}
	copy[index] = NULL;
	return (copy);
}
