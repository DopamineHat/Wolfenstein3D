/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rainclusterfuck.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpagot <rpagot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/23 02:08:58 by rpagot            #+#    #+#             */
/*   Updated: 2017/10/23 02:09:08 by rpagot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rainclusterfuck.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpagot <rpagot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/17 17:42:31 by rpagot            #+#    #+#             */
/*   Updated: 2017/10/23 02:06:34 by rpagot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void		ft_print_position(t_env *e)
{
	char *tmp;

	mlx_string_put(e->mlx.mlx, e->mlx.win, WIDTH - 220, 50, 0x00FFFFFF,
			"POSITION :");
	tmp = ft_itoa(e->player.pos.y);
	mlx_string_put(e->mlx.mlx, e->mlx.win, WIDTH - 110, 50, 0x00FFFFFF,
			tmp);
	mlx_string_put(e->mlx.mlx, e->mlx.win, WIDTH - 80, 50, 0x00FFFFFF,
			",");
	free(tmp);
	tmp = ft_itoa(e->player.pos.x);
	mlx_string_put(e->mlx.mlx, e->mlx.win, WIDTH - 60, 50, 0x00FFFFFF,
			tmp);
	free(tmp);
}

void		ft_print_weather(t_env *e)
{
	mlx_string_put(e->mlx.mlx, e->mlx.win,
				WIDTH - 200, 10, 0x00FFFFFF, "STATUS :");
	if (!e->rainrate)
		mlx_string_put(e->mlx.mlx, e->mlx.win,
				WIDTH - 110, 10, 0x00FFFF00, "sunny");
	if (e->rainrate && e->rainrate >= 8)
		mlx_string_put(e->mlx.mlx, e->mlx.win,
				WIDTH - 110, 10, 0x00c0c0F0, "drizzling");
	if (e->rainrate && e->rainrate >= 1 && e->rainrate < 8)
		mlx_string_put(e->mlx.mlx, e->mlx.win,
				WIDTH - 110, 10, 0x008080F0, "rainy");
	if (e->rainrate && e->rainrate < 1 && e->rainrate >= .2f)
		mlx_string_put(e->mlx.mlx, e->mlx.win,
				WIDTH - 110, 10, 0x004040F0, "waterflood");
	if (e->rainrate && e->rainrate < .2f)
		mlx_string_put(e->mlx.mlx, e->mlx.win,
				WIDTH - 110, 10, 0x00606060, "storm");
}

void		ft_raindrops(t_env *e, int y2, int x1)
{
	if (!(e->mlx.addrpxl[x1 + y2 * WIDTH] << 24)
				&& (y2 > HEIGHT * 3 / 4) && y2 < HEIGHT - 4)
	{
		e->mlx.addrpxl[x1 + (y2 + 3) * WIDTH] = 0x00FFFFFF;
		e->mlx.addrpxl[x1 + 3 + y2 * WIDTH] = 0x00FFFFFF;
		e->mlx.addrpxl[x1 - 3 + y2 * WIDTH] = 0x00FFFFFF;
	}
	else if (!(e->mlx.addrpxl[x1 + y2 * WIDTH] << 24)
				&& (y2 > HEIGHT * 5 / 8) && y2 <= HEIGHT * 3 / 4)
	{
		ft_pixel(e, x1, y2 + 2, 0x00FFFFFF);
		ft_pixel(e, x1 + 2, y2, 0x00FFFFFF);
		ft_pixel(e, x1 - 2, y2, 0x00FFFFFF);
		e->mlx.addrpxl[x1 + (y2 + 2) * WIDTH] = 0x00FFFFFF;
		e->mlx.addrpxl[x1 + 2 + y2 * WIDTH] = 0x00FFFFFF;
		e->mlx.addrpxl[x1 - 2 + y2 * WIDTH] = 0x00FFFFFF;
	}
	else if (!(e->mlx.addrpxl[x1 + y2 * WIDTH] << 24)
				&& (y2 > HEIGHT * 9 / 16) && y2 <= HEIGHT * 5 / 8)
	{
		e->mlx.addrpxl[x1 + 1 + (y2 - 1) * WIDTH] = 0x00FFFFFF;
		e->mlx.addrpxl[x1 - 1 + (y2 - 1) * WIDTH] = 0x00FFFFFF;
	}
	else if (!(e->mlx.addrpxl[x1 + y2 * WIDTH] << 24) && y2 <= HEIGHT * 9 / 16)
		e->mlx.addrpxl[x1 + y2 * WIDTH] = 0x00FFFFFF;
}

void		ft_rainprocess(t_env *e, int x1)
{
	int y1;
	int y2;

	x1 -= WIDTH / 64;
	y1 = ((rand() % (((HEIGHT)) + 50)) - 50);
	y2 = ((rand() % (HEIGHT / 8)) + y1);
	if (y2 >= HEIGHT)
		y2 = HEIGHT - 1;
	if (y1 < 1)
		y1 = 1;
	if (y2 < 1)
		y2 = 1;
	ft_raindrops(e, y2, x1);
	while (y2-- > y1)
		ft_pixel(e, x1, y2, 0xa0FFFFFF);
	if (!y2 || !y1)
		return ;
	while (y1-- > y2)
		ft_pixel(e, x1, y2, 0xa0FFFFFF);
}
