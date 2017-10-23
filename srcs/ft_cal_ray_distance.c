/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cal_ray_distance.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpagot <rpagot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/22 19:06:47 by rpagot            #+#    #+#             */
/*   Updated: 2017/10/22 19:26:02 by rpagot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void			ft_cal_ray_dist(t_env *e)
{
	if (e->map[e->ray.map.x][e->ray.map.y] > 0)
	{
		e->ray.hit = 1;
		if (e->ray.hit_side == 0)
		{
			e->ray.dist = (e->ray.map.x - e->ray.pos.x + (1 - e->ray.step.x)
					/ 2) / e->ray.dir.x;
		}
		else
		{
			e->ray.dist = (e->ray.map.y - e->ray.pos.y + (1 - e->ray.step.y)
					/ 2) / e->ray.dir.y;
		}
	}
}
