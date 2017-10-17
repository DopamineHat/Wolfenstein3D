/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpagot <rpagot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/14 05:39:38 by rpagot            #+#    #+#             */
/*   Updated: 2017/10/17 02:25:24 by rpagot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

static void		init_thunderyellow(t_env *e)
{
	int i;

	i = -1;
	while((i + 3) < WIDTH * HEIGHT * 4)
	{
		e->mlx.pxlyellow[++i] = 0x00;
		e->mlx.pxlyellow[++i] = 0xFF;
		e->mlx.pxlyellow[++i] = 0xFF;
		++i;
	}
}

static void		init_thunder(t_env *e)
{
	int i;

	i = -1;
	while((i + 3) < WIDTH * HEIGHT * 4)
	{
		e->mlx.pxlwhite[++i] = 0xFF;
		e->mlx.pxlwhite[++i] = 0xFF;
		e->mlx.pxlwhite[++i] = 0xFF;
		++i;
	}
}
static void		init_img(t_env *e)
{
	int h;
	int w;
	if (open("./srcs/images/W_KEY_LITAF.xpm", O_RDONLY) > 0)
		e->image.img0 = mlx_xpm_file_to_image(e->mlx.mlx,
				"./srcs/images/W_KEY_LITAF.xpm", &w, &h);
	if (open("./srcs/images/S_KEY_LITAF.xpm", O_RDONLY) > 0)
		e->image.img1 = mlx_xpm_file_to_image(e->mlx.mlx,
				"./srcs/images/S_KEY_LITAF.xpm", &w, &h);
	if (open("./srcs/images/A_KEY_LITAF.xpm", O_RDONLY) > 0)
		e->image.img2 = mlx_xpm_file_to_image(e->mlx.mlx,
				"./srcs/images/A_KEY_LITAF.xpm", &w, &h);
	if (open("./srcs/images/D_KEY_LITAF.xpm", O_RDONLY) > 0)
		e->image.img3 = mlx_xpm_file_to_image(e->mlx.mlx,
				"./srcs/images/D_KEY_LITAF.xpm", &w, &h);
}
static void		init_player(t_env *e)
{
	e->player.pos.x = 0;
	e->player.pos.y = 0;
	e->player.dir.x = -1;
	e->player.dir.y = 0;
	e->player.plan.x = 0;
	e->player.plan.y = 0.66;
	e->player.speed_turn = 0.0625;
	e->player.speed_move = 0.125;
	e->player.move_up = 0;
	e->player.move_down = 0;
	e->player.move_right = 0;
	e->player.move_left = 0;
}

static void		init_mlx(t_env *e)
{
	e->mlx.fps = 0;
	e->time = 0;
	e->oldtime = time(NULL);
	e->mlx.mlx = mlx_init();
	e->mlx.bpp = 0;
	e->mlx.s_line = 0;
	e->mlx.img = mlx_new_image(e->mlx.mlx, WIDTH, HEIGHT);
	e->mlx.white = mlx_new_image(e->mlx.mlx, WIDTH, HEIGHT);
	e->mlx.pxlwhite = mlx_get_data_addr(e->mlx.white, &(e->mlx.bpp), &(e->mlx.s_line),
			&(e->mlx.ed));
	e->mlx.yellow = mlx_new_image(e->mlx.mlx, WIDTH, HEIGHT);
	e->mlx.pxlyellow = mlx_get_data_addr(e->mlx.yellow, &(e->mlx.bpp), &(e->mlx.s_line),
			&(e->mlx.ed));
	init_thunder(e);
	init_thunderyellow(e);
	e->mlx.pxl = mlx_get_data_addr(e->mlx.img, &(e->mlx.bpp), &(e->mlx.s_line),
			&(e->mlx.ed));
	e->mlx.next_frame = 0;
	e->i = 0;
}

t_env			*init_env(void)
{
	t_env	*e;

	if (!(e = (t_env *)malloc(sizeof(t_env))))
		error_malloc();
	e->width = WIDTH;
	e->height = HEIGHT;
	init_player(e);
	init_mlx(e);
	init_img(e);
	e->color_1 =		0x8080b0;
	e->color_2 =		0xa0a0d0;
	e->color_3 =		0xc0c0f0;
	e->color_4 =		0x606090;
	e->color_sky =		0x002366;
	e->color_ground =	0xff0000;
	return (e);
}
