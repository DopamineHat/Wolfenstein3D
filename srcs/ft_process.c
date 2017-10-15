/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpagot <rpagot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/14 05:41:22 by rpagot            #+#    #+#             */
/*   Updated: 2017/10/15 23:26:31 by rpagot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

static void		ft_print_inputs(t_env *e)
{
	int w;
	int h;

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
	}
	mlx_string_put(e->mlx.mlx, e->mlx.win, 10, 10, 0x00FFFFFF,
			"FPS:");
	mlx_string_put(e->mlx.mlx, e->mlx.win, 50, 10, 0x00FFFFFF,
			ft_itoa((int)e->mlx.fps));
	ft_print_inputs(e);
}

int				ft_loop_hook(t_env *e)
{
	e->mlx.next_frame++;
	if (e->player.move_up)
		move_up(e);
	if (e->player.move_down)
		move_down(e);
	if (e->player.move_right)
		move_right(e);
	if (e->player.move_left)
		move_left(e);
	raycasting(e);
	mlx_put_image_to_window(e->mlx.mlx, e->mlx.win, e->mlx.img, 0, 0);
	ft_display_info(e);
	return (0);
}
