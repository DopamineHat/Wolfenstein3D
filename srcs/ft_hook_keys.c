/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hook_keys.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpagot <rpagot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/14 05:39:23 by rpagot            #+#    #+#             */
/*   Updated: 2017/10/18 22:23:31 by rpagot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

static void		ft_movements(int k, t_env *e)
{
	if (k == KEY_W)
		e->player.move_up = !e->player.move_up;
	if (k == KEY_S)
		e->player.move_down = !e->player.move_down;
	if (k == KEY_A)
		e->player.move_left = !e->player.move_left;
	if (k == KEY_D)
		e->player.move_right = !e->player.move_right;
	if (k == KEY_PAD_SUB)
	{
		if (e->rainrate < 32)
			e->rainrate *= 1.25f;
		else
			e->rainrate = 0;
	}
	if (k == KEY_PAD_ADD)
	{
		if (e->rainrate == 0)
			e->rainrate = 32;
		else
			if (e->rainrate > .02f)
				e->rainrate *= 0.8f;
	}
}

int				ft_key_move(int k, t_env *e)
{
	ft_movements(k, e);
	if (k == KEY_ESC)
	{
		mlx_destroy_window(e->mlx.mlx, e->mlx.win);
		exit(0);
	}
	if (e->rainrate)
		e->brightness =			((int)sqrt((double)e->rainrate) << 11)
							+	((int)sqrt((double)e->rainrate) << 19)
							+	((int)sqrt((double)e->rainrate) << 3);
	else
		e->brightness = 0x00303030;
	return (0);
}
