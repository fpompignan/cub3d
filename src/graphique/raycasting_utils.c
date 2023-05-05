/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fassier- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 12:09:28 by fassier-          #+#    #+#             */
/*   Updated: 2022/10/21 12:48:47 by fassier-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	calculate_distance_projected(t_board *board)
{
	if (board->ray.side == 0)
		board->ray.perpwalldist = ((double)board->ray.mapx - \
		board->ray.posx + (1 - (double)board->ray.stepx) / 2) / \
			board->ray.raydirx;
	else
		board->ray.perpwalldist = ((double)board->ray.mapy - \
		board->ray.posy + (1 - (double)board->ray.stepy) / 2) / \
			board->ray.raydiry;
}

void	calculate_lowest_and_highest_pixel_to_fill(t_board *board)
{
	board->ray.drawstart = -board->ray.lineheight / 2 + board->ry / 2;
	if (board->ray.drawstart < 0 || board->ray.drawstart >= board->ry)
		board->ray.drawstart = 0;
	board->ray.drawend = board->ray.lineheight / 2 + board->ry / 2;
	if (board->ray.drawend >= board->ry || board->ray.drawend < 0)
		board->ray.drawend = board->ry - 1;
}

void	ft_init_texture_image(t_board *board)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		board->texture[i].img = NULL;
		board->texture[i].addr = NULL;
		board->texture[i].bits_per_pixel = 0;
		board->texture[i].line_length = 0;
		board->texture[i].endian = 0;
		board->texture[i].width = 0;
		board->texture[i].height = 0;
		i++;
	}
}
