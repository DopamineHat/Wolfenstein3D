/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arraypop.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeletan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 01:02:26 by adeletan          #+#    #+#             */
/*   Updated: 2017/03/08 01:19:10 by adeletan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

char	**ft_arraypop(char **tab, size_t index, int free)
{
	if (free == 1)
		ft_strdel(&tab[index]);
	while (tab[index + 1] || index == 0)
	{
		tab[index] = tab[index + 1];
		tab[index + 1] = NULL;
		++index;
	}
	tab[index] = NULL;
	return (tab);
}
