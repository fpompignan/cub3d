/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fassier- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 16:06:23 by fassier-          #+#    #+#             */
/*   Updated: 2022/10/20 16:02:26 by fassier-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int	ft_exit(t_board *board)
{
	if (board->img)
		mlx_destroy_image(board->mlx, board->img);
	if (board->texture[0].img)
		mlx_destroy_image(board->mlx, board->texture[0].img);
	if (board->texture[1].img)
		mlx_destroy_image(board->mlx, board->texture[1].img);
	if (board->texture[2].img)
		mlx_destroy_image(board->mlx, board->texture[2].img);
	if (board->texture[3].img)
		mlx_destroy_image(board->mlx, board->texture[3].img);
	if (board->win)
		mlx_destroy_window(board->mlx, board->win);
	if (board->mlx)
	{
		mlx_destroy_display(board->mlx);
		free(board->mlx);
	}
	exit_wolf(board);
	exit(0);
}
