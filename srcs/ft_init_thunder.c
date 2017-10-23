/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_thunder.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpagot <rpagot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/22 19:09:30 by rpagot            #+#    #+#             */
/*   Updated: 2017/10/22 19:33:03 by rpagot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void			init_thunderyellow(t_env *e)
{
	int i;

	i = -1;
	while (++i < WIDTH * HEIGHT)
		e->mlx.addryellow[i] = 0x40FFFF00;
}

void			init_thunder(t_env *e)
{
	int i;

	i = -1;
	while (++i < WIDTH * HEIGHT)
		e->mlx.addrwhite[i] = 0xa0FFFFFF;
}

void			ft_init_colors(t_env *e)
{
	e->color_1 = 0x505080 + e->brightness;
	e->color_2 = 0x7070a0 + e->brightness;
	e->color_3 = 0x9090c0 + e->brightness;
	e->color_4 = 0x303060 + e->brightness;
	e->color_sky = 0x000346 + e->brightness;
	e->color_ground = 0x00bf00 + e->brightness;
}
