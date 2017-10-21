/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpagot <rpagot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/14 05:40:48 by rpagot            #+#    #+#             */
/*   Updated: 2017/10/21 17:56:01 by rpagot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

static void		read_pos(int fd, t_env *e)
{
	char	*line;
	char	**line_split;
	int		i;

	i = -1;
	if (get_next_line(fd, &line) < 1)
		error_map();
	line_split = ft_strsplit(line, ' ');
	while (line_split[++i] != '\0')
		;
	if (i != 4)
		error_map();
	e->map_width = ft_atoi(line_split[0]);
	e->map_height = ft_atoi(line_split[1]);
	e->player.pos.x = ft_atoi(line_split[2]) + 0.5f;
	e->player.pos.y = ft_atoi(line_split[3]) + 0.5f;
	if (e->map_width < 0 || e->map_height < 0 || e->player.pos.x < 0 ||
			e->player.pos.y < 0 || e->player.pos.x >= e->map_width ||
			e->player.pos.y >= e->map_width)
		error_map();
	free (line);
	while (i >= 0)
		free(line_split[i--]);
	free(line_split);
}

static void		read_line(char *line, int y, t_env *e)
{
	int		x;
	char	**line_split;

	x = -1;
	if (y >= e->map_height)
		error_map();
	line_split = ft_strsplit(line, ' ');
	if (!(e->map[y] = (int *)malloc(sizeof(int *) * e->width)))
		error_malloc();
	while (line_split[++x] != '\0')
	{
		if (!(line_split[x][0] >= '0' && line_split[x][0] <= '9'
					&& ft_atoi(line_split[x]) >= 0 && x < e->map_width))
			error_map();
		e->map[y][x] = ft_atoi(line_split[x]);
		if ((x == 0 || x == e->map_width - 1 || y == 0 || y == e->map_height -
					1) && e->map[y][x] == 0)
			error_map();
		free(line_split[x]);
	}
	free(line_split[x]);
	free(line_split);
	if (x != e->map_width)
	{
		free(line);
		error_map();
	}
	free(line);
}

static int		read_file(int fd, t_env *e)
{
	char	*line;
	int		y;

	y = -1;
	read_pos(fd, e);
	if(!(e->map = (int **)malloc(sizeof(int **) * e->map_height)))
		error_malloc();
	while (get_next_line(fd, &line) == 1)
		read_line(line, ++y, e);
	if (e->map[(int)e->player.pos.x][(int)e->player.pos.y] != 0)
		error_map();
	return (1);
}

int				open_file(t_env *e, char *str)
{
	int		fd;

	fd = open(str, O_RDONLY);
	if (fd < 0)
		return (0);
	return (read_file(fd, e));
}
