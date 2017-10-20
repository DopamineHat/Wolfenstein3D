/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpagot <rpagot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/14 05:41:22 by rpagot            #+#    #+#             */
/*   Updated: 2017/10/20 07:08:15 by rpagot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

static void		ft_rain(t_env *e)
{
	int x;
	int i;

	i = 0;
	e->i = WIDTH / 64;
	if (e->rainrate)
	{
		while (e->i < WIDTH)
		{
			while (e->mlx.stockdist[e->i] < HEIGHT * 2)
			{
				e->mlx.stockdist[e->i] *= e->rainrate + 1;
				x = (rand() % (WIDTH / 32 - 1)) + (WIDTH / 32) * i + WIDTH / 64;
				ft_rainprocess(e, x);
			}
			e->i += WIDTH / 32;
			++i;
		}
	}
	e->i = 0;
}

static void		ft_thunder(t_env *e)
{
	if (e->rainrate && e->rainrate < .2f)
	{
		if (e->time && !(e->time % 8) && (e->mlx.next_frame < 1))
			mlx_put_image_to_window(e->mlx.mlx, e->mlx.win, e->mlx.yellow, 0, 0);
		if (e->time && !(e->time % 8) && (e->mlx.next_frame < 16)
				&& e->mlx.next_frame > 4)
			mlx_put_image_to_window(e->mlx.mlx, e->mlx.win, e->mlx.white, 0, 0);
		if (e->time && !(e->time % 8) && (e->mlx.next_frame < 40)
				&& (e->mlx.next_frame > 30))
			mlx_put_image_to_window(e->mlx.mlx, e->mlx.win, e->mlx.white, 0, 0);
	}
}

static void		ft_print_inputs(t_env *e)
{
	if (e->player.move_up != 0)
		mlx_put_image_to_window(e->mlx.mlx, e->mlx.win,
				e->image.img0, 110, 1000);
	if (e->player.move_down != 0)
		mlx_put_image_to_window(e->mlx.mlx, e->mlx.win,
				e->image.img1, 110, 1080);
	if (e->player.move_left != 0)
		mlx_put_image_to_window(e->mlx.mlx, e->mlx.win,
				e->image.img2, 30, 1080);
	if (e->player.move_right != 0)
		mlx_put_image_to_window(e->mlx.mlx, e->mlx.win,
				e->image.img3, 190, 1080);
}

static void		ft_display_info(t_env *e)
{
	if (e->oldtime != time(NULL))
	{
		e->oldtime = time(NULL);
		e->mlx.fps = e->mlx.next_frame;
		e->mlx.next_frame = 0;
		e->time++;
	}
	mlx_string_put(e->mlx.mlx, e->mlx.win, 10, 10, 0x00FFFFFF,
			"FPS:");
	mlx_string_put(e->mlx.mlx, e->mlx.win, 60, 10, 0x00FFFFFF,
			ft_itoa((int)e->mlx.fps));
	mlx_string_put(e->mlx.mlx, e->mlx.win, 10, 40, 0x00FFFFFF,
			"TIME:");
	mlx_string_put(e->mlx.mlx, e->mlx.win, 70, 40, 0x00FFFFFF,
			ft_itoa((int)e->time));
	ft_print_inputs(e);
	ft_print_weather(e);
}

int				ft_loop_hook(t_env *e)
{
	int i;

	i = 0;
	e->mlx.next_frame++;
	ft_init_colors(e);
	if (e->player.move_up)
		move_up(e);
	if (e->player.move_down)
		move_down(e);
	if (e->player.move_right)
		move_right(e);
	if (e->player.move_left)
		move_left(e);
	raycasting(e);
	ft_rain(e);
	mlx_put_image_to_window(e->mlx.mlx, e->mlx.win, e->mlx.img, 0, 0);
	ft_display_info(e);
	ft_thunder(e);
	return (0);
}
