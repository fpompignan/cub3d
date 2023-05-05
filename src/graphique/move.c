/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fassier- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 14:57:49 by fassier-          #+#    #+#             */
/*   Updated: 2022/10/19 16:25:28 by fassier-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	ft_forward_back(t_board *board)
{
	if (board->forward == 1)
	{
		if (board->map[(int)(board->ray.posx + board->ray.dirx * \
		board->ray.movespeed)][(int)(board->ray.posy)] == '0')
			board->ray.posx += board->ray.dirx * board->ray.movespeed;
		if (board->map[(int)(board->ray.posx)][(int)(board->ray.posy + \
		board->ray.diry * board->ray.movespeed)] == '0')
			board->ray.posy += board->ray.diry * board->ray.movespeed;
	}
	if (board->back == 1)
	{
		if (board->map[(int)(board->ray.posx - board->ray.dirx * \
		board->ray.movespeed)][(int)(board->ray.posy)] == '0')
			board->ray.posx -= board->ray.dirx * board->ray.movespeed;
		if (board->map[(int)(board->ray.posx)][(int)(board->ray.posy - \
		board->ray.diry * board->ray.movespeed)] == '0')
			board->ray.posy -= board->ray.diry * board->ray.movespeed;
	}
}

void	ft_left_right(t_board *board)
{
	if (board->right == 1)
	{
		if (board->map[(int)(board->ray.posx + board->ray.diry * \
		board->ray.movespeed)][(int)(board->ray.posy)] == '0')
			board->ray.posx += board->ray.diry * board->ray.movespeed;
		if (board->map[(int)(board->ray.posx)][(int)(board->ray.posy - \
		board->ray.dirx * board->ray.movespeed)] == '0')
			board->ray.posy -= board->ray.dirx * board->ray.movespeed;
	}
	if (board->left == 1)
	{
		if (board->map[(int)(board->ray.posx - board->ray.diry * \
		board->ray.movespeed)][(int)(board->ray.posy)] == '0')
			board->ray.posx -= board->ray.diry * board->ray.movespeed;
		if (board->map[(int)(board->ray.posx)][(int)(board->ray.posy + \
		board->ray.dirx * board->ray.movespeed)] == '0')
			board->ray.posy += board->ray.dirx * board->ray.movespeed;
	}
}

static void	f_right(t_board *board, double olddir_x, double oldplan_x)
{
	board->ray.dirx = board->ray.dirx * cos(-board->ray.rotspeed / 2) - \
	board->ray.diry * sin(-board->ray.rotspeed / 2);
	board->ray.diry = olddir_x * sin(-board->ray.rotspeed / 2) + \
	board->ray.diry * cos(-board->ray.rotspeed / 2);
	board->ray.planex = board->ray.planex * cos(-board->ray.rotspeed / 2) - \
	board->ray.planey * sin(-board->ray.rotspeed / 2);
	board->ray.planey = oldplan_x * sin(-board->ray.rotspeed / 2) + \
	board->ray.planey * cos(-board->ray.rotspeed / 2);
}

static void	f_left(t_board *board, double olddir_x, double oldplan_x)
{
	board->ray.dirx = board->ray.dirx * cos(board->ray.rotspeed / 2) - \
	board->ray.diry * sin(board->ray.rotspeed / 2);
	board->ray.diry = olddir_x * sin(board->ray.rotspeed / 2) + \
	board->ray.diry * cos(board->ray.rotspeed / 2);
	board->ray.planex = board->ray.planex * cos(board->ray.rotspeed / 2) - \
	board->ray.planey * sin(board->ray.rotspeed / 2);
	board->ray.planey = oldplan_x * sin(board->ray.rotspeed / 2) + \
	board->ray.planey * cos(board->ray.rotspeed / 2);
}	

void	ft_rotate(t_board *board)
{
	double	olddir_x;
	double	oldplan_x;

	olddir_x = board->ray.dirx;
	oldplan_x = board->ray.planex;
	if (board->r_right == 1)
		f_right(board, olddir_x, oldplan_x);
	if (board->r_left == 1)
		f_left(board, olddir_x, oldplan_x);
}
