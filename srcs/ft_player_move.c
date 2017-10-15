/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_player_move.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpagot <rpagot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/14 05:41:04 by rpagot            #+#    #+#             */
/*   Updated: 2017/10/15 14:31:42 by rpagot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	move_up(t_env *e)
{
	if (e->map[(int)(e->player.pos.x + e->player.dir.x * e->player.speed_move)]
			[(int)e->player.pos.y] == 0)
		e->player.pos.x += e->player.dir.x * e->player.speed_move;
	if (e->map[(int)e->player.pos.x][(int)(e->player.pos.y + e->player.dir.y *
				e->player.speed_move)] == 0)
		e->player.pos.y += e->player.dir.y * e->player.speed_move;
}

void	move_down(t_env *e)
{
	if (e->map[(int)(e->player.pos.x - e->player.dir.x * e->player.speed_move)]
			[(int)e->player.pos.y] == 0)
		e->player.pos.x -= e->player.dir.x * e->player.speed_move;
	if (e->map[(int)e->player.pos.x][(int)(e->player.pos.y - e->player.dir.y *
				e->player.speed_move)] == 0)
		e->player.pos.y -= e->player.dir.y * e->player.speed_move;
}

void	move_left(t_env *e)
{
	t_dxy	last;

	last.x = e->player.dir.x;
	e->player.dir.x = e->player.dir.x * cos(e->player.speed_turn) -
		e->player.dir.y * sin(e->player.speed_turn);
	e->player.dir.y = last.x * sin(e->player.speed_turn) + e->player.dir.y *
		cos(e->player.speed_turn);
	last.x = e->player.plane.x;
	e->player.plane.x = e->player.plane.x * cos(e->player.speed_turn) -
		e->player.plane.y * sin(e->player.speed_turn);
	e->player.plane.y = last.x * sin(e->player.speed_turn) + e->player.plane.y *
		cos(e->player.speed_turn);
}

void	move_right(t_env *e)
{
	t_dxy	last;

	last.x = e->player.dir.x;
	e->player.dir.x = e->player.dir.x * cos(-e->player.speed_turn) -
		e->player.dir.y * sin(-e->player.speed_turn);
	e->player.dir.y = last.x * sin(-e->player.speed_turn) + e->player.dir.y *
		cos(-e->player.speed_turn);
	last.x = e->player.plane.x;
	e->player.plane.x = e->player.plane.x * cos(-e->player.speed_turn) -
		e->player.plane.y * sin(-e->player.speed_turn);
	e->player.plane.y = last.x * sin(-e->player.speed_turn) + e->player.plane.y *
		cos(-e->player.speed_turn);
}
