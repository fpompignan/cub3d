/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config_board_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fassier- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 15:23:26 by fassier-          #+#    #+#             */
/*   Updated: 2022/10/21 13:00:00 by fassier-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	init_board(t_board *board, t_parsing *info)
{
	board->plafond = info->plafond;
	board->sol = info->sol;
	board->width = info->width;
	board->height = info->length;
	board->forward = 0;
	board->back = 0;
	board->left = 0;
	board->right = 0;
	board->r_left = 0;
	board->r_right = 0;
	board->start_i = 0;
	board->start_j = 0;
	board->start_direction = 0;
	board->rx = 1000;
	board->ry = 1000;
	board->img = NULL;
	copy_texture_cardinal(board, info);
	copy_map(board, info);
	ft_init_texture_image(board);
}

void	init_player(t_board *board)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < board->height)
	{
		while (j < board->width)
		{
			if (board->maps[i][j] == NORTH || board->maps[i][j] == EAST || \
				board->maps[i][j] == SOUTH || board->maps[i][j] == WEST)
			{
				board->start_i = i;
				board->start_j = j;
				board->start_direction = board->maps[i][j];
			}
			j++;
		}
		j = 0;
		i++;
	}
}

int	init_window(t_board *board)
{
	board->mlx = mlx_init();
	if (!board->mlx)
		exit_wolf(board);
	board->win = mlx_new_window(board->mlx, board->rx,
			board->ry, "wolfenstein3D");
	if (!board->win)
		ft_exit(board);
	return (0);
}

static void	init_dir_and_plane(t_board *board)
{
	board->ray.dirx = 0;
	board->ray.diry = 0;
	board->ray.planex = 0;
	board->ray.planey = 0;
	if (board->start_direction == NORTH)
	{
		board->ray.dirx = -1;
		board->ray.planey = 0.66;
	}
	if (board->start_direction == SOUTH)
	{
		board->ray.dirx = 1;
		board->ray.planey = -0.66;
	}
	if (board->start_direction == WEST)
	{
		board->ray.diry = -1;
		board->ray.planex = -0.66;
	}
	if (board->start_direction == EAST)
	{
		board->ray.diry = 1;
		board->ray.planex = 0.66;
	}
}

void	init_ray(t_board *board)
{
	board->ray.posx = board->start_i + 0.5;
	board->ray.posy = board->start_j + 0.5;
	board->map[board->start_i][board->start_j] = '0';
	board->maps[board->start_i][board->start_j] = 0;
	init_dir_and_plane(board);
	board->ray.movespeed = 0.1;
	board->ray.rotspeed = 0.033 * 1.8;
}
