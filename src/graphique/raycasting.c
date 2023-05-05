/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fassier- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 11:09:44 by fassier-          #+#    #+#             */
/*   Updated: 2022/10/21 12:46:48 by fassier-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

static int	ft_color_column(t_board *board)
{
	int	j;
	int	i;

	j = -1;
	i = board->ray.drawend;
	while (++j < board->ray.drawstart)
		board->addr[j * board->line_length / 4 + board->ray.x] = board->plafond;
	if (j <= board->ray.drawend)
		ft_draw_texture(board, board->ray.x, j);
	j = i;
	while (++j < board->ry)
		board->addr[j * board->line_length / 4 + \
			board->ray.x] = board->sol;
	return (0);
}

static void	ft_position(t_board *board)
{
	board->ray.camerax = (2 * board->ray.x / (double)board->rx) - 1;
	board->ray.raydirx = board->ray.dirx + \
		(board->ray.planex * board->ray.camerax);
	board->ray.raydiry = board->ray.diry + \
		(board->ray.planey * board->ray.camerax);
	board->ray.mapx = (int)board->ray.posx;
	board->ray.mapy = (int)board->ray.posy;
	if (!board->ray.raydirx)
		board->ray.deltadistx = 1e30;
	else
		board->ray.deltadistx = sqrt(1 + (board->ray.raydiry * \
		board->ray.raydiry) / (board->ray.raydirx * board->ray.raydirx));
	if (!board->ray.raydiry)
		board->ray.deltadisty = 1e30;
	else
		board->ray.deltadisty = sqrt(1 + (board->ray.raydirx * \
		board->ray.raydirx) / (board->ray.raydiry * board->ray.raydiry));
}

static void	calculate_step_and_initial_sidedist(t_board *board)
{
	if (board->ray.raydirx < 0)
	{
		board->ray.stepx = -1;
		board->ray.sidedistx = (board->ray.posx - board->ray.mapx) * \
			board->ray.deltadistx;
	}
	else
	{
		board->ray.stepx = 1;
		board->ray.sidedistx = (board->ray.mapx + 1 - board->ray.posx) * \
			board->ray.deltadistx;
	}
	if (board->ray.raydiry < 0)
	{
		board->ray.stepy = -1;
		board->ray.sidedisty = (board->ray.posy - board->ray.mapy) * \
			board->ray.deltadisty;
	}
	else
	{
		board->ray.stepy = 1;
		board->ray.sidedisty = (board->ray.mapy + 1 - board->ray.posy) * \
			board->ray.deltadisty;
	}
}

static void	launch_dda(t_board *board)
{
	while (board->ray.hit == 0)
	{
		if (board->ray.sidedistx < board->ray.sidedisty)
		{
			board->ray.sidedistx = board->ray.sidedistx + board->ray.deltadistx;
			board->ray.mapx = board->ray.mapx + board->ray.stepx;
			board->ray.side = 0;
		}
		else
		{
			board->ray.sidedisty = board->ray.sidedisty + board->ray.deltadisty;
			board->ray.mapy = board->ray.mapy + board->ray.stepy;
			board->ray.side = 1;
		}
		if (board->maps[board->ray.mapx][board->ray.mapy] > 0)
			board->ray.hit = 1;
	}
}

int	ft_raycasting(t_board *board)
{
	board->ray.x = 0;
	while (board->ray.x < board->rx)
	{
		ft_position(board);
		board->ray.hit = 0;
		calculate_step_and_initial_sidedist(board);
		launch_dda(board);
		calculate_distance_projected(board);
		board->ray.lineheight = (int)(board->ry / board->ray.perpwalldist);
		calculate_lowest_and_highest_pixel_to_fill(board);
		ft_color_column(board);
		board->ray.x++;
	}
	mlx_put_image_to_window(board->mlx, board->win, board->img, 0, 0);
	ft_forward_back(board);
	ft_left_right(board);
	ft_rotate(board);
	return (0);
}
