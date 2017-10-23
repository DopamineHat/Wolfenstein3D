/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpagot <rpagot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/14 05:38:57 by rpagot            #+#    #+#             */
/*   Updated: 2017/10/23 04:42:28 by rpagot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void					ft_pixel(t_env *e, int x, int y, unsigned int c)
{
	e->mlx.addrpxl[x + y * WIDTH] = c;
}

unsigned int			get_color(t_env *e)
{
	if (e->ray.hit_side == 1)
	{
		if ((e->ray.step.x == -1 && e->ray.step.y == -1) ||
			(e->ray.step.x == 1 && e->ray.step.y == -1))
			return (e->color_1);
		if ((e->ray.step.x == -1 && e->ray.step.y == 1) ||
			(e->ray.step.x == 1 && e->ray.step.y == 1))
			return (e->color_2);
	}
	if ((e->ray.step.x == -1 && e->ray.step.y == -1) ||
		(e->ray.step.x == -1 && e->ray.step.y == 1))
		return (e->color_3);
	else
		return (e->color_4);
	return (0);
}

static unsigned int		add_shader(unsigned int c, double d)
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;

	b = c;
	g = c >> 8;
	r = c >> 16;
	d /= 32;
	if (d > 0.9)
		d = 0.9;
	if (r > 0)
		r -= (r * d);
	if (g > 0)
		g -= (g * d);
	if (b > 0)
		b -= (b * d);
	return ((r << 16) + (g << 8) + b);
}

void					draw_line(t_env *e, int x, int start, int end)
{
	int				i;
	unsigned int	c;

	c = get_color(e);
	c = add_shader(c, e->ray.dist);
	i = -1;
	while (++i < start)
		ft_pixel(e, x, i, e->color_sky);
	i--;
	while (++i <= end && i < e->height)
		ft_pixel(e, x, i, c);
	i--;
	while (++i < e->height)
		ft_pixel(e, x, i, add_shader(e->color_ground,
					abs(i - e->height) * 0.04));
}
