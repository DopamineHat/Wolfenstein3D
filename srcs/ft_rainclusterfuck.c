/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rainclusterfuck.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpagot <rpagot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/17 17:42:31 by rpagot            #+#    #+#             */
/*   Updated: 2017/10/17 18:18:15 by rpagot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void		ft_rainprocess(t_env *e, int x1)
{
	int y1;
	int y2;

	y1 = (rand() % ((HEIGHT - 1) + 200)) - 200;
	y2 = (rand() % ((HEIGHT - 1) + 200)) - 200;
	if (y1 < 1)
		y1 = 1;
	if (y2 < 1)
		y2 = 1;
	if (y2 > y1 && !e->mlx.pxl[(x1 * 4) + (y2 * e->mlx.s_line) + 1])
	{
		ft_pixel(e, x1, y2 + 3, 0x00FFFFFF);
		ft_pixel(e, x1 + 3, y2, 0x00FFFFFF);
		ft_pixel(e, x1 - 3, y2, 0x00FFFFFF);
	}
	if (y1 > y2 && !e->mlx.pxl[(x1 * 4) + (y1 * e->mlx.s_line) + 1])
	{
		ft_pixel(e, x1, y1 + 3, 0x00FFFFFF);
		ft_pixel(e, x1 + 3, y1, 0x00FFFFFF);
		ft_pixel(e, x1 - 3, y1, 0x00FFFFFF);
	}
	while(y2-- > y1)
		ft_pixel(e, x1, y2, 0x00FFFFFF);
	if (!y2 || !y1)
	  return ;
	while(y1-- > y2)
		ft_pixel(e, x1, y2, 0x00FFFFFF);
}
