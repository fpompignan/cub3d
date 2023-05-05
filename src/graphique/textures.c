/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fassier- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 15:46:42 by fassier-          #+#    #+#             */
/*   Updated: 2022/10/20 15:14:08 by fassier-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	ft_error(t_board *board, char *str)
{
	write(1, "Error\n", 6);
	write(1, str, ft_strlen(str));
	ft_exit(board);
}

void	ft_init_texture(t_board *board)
{
	if (board->ray.side == 0 && board->ray.raydirx < 0)
		board->t.texdir = 0;
	if (board->ray.side == 0 && board->ray.raydirx >= 0)
		board->t.texdir = 1;
	if (board->ray.side == 1 && board->ray.raydiry < 0)
		board->t.texdir = 2;
	if (board->ray.side == 1 && board->ray.raydiry >= 0)
		board->t.texdir = 3;
	if (board->ray.side == 0)
		board->t.wallx = board->ray.posy + board->ray.perpwalldist \
						* board->ray.raydiry;
	else
		board->t.wallx = board->ray.posx + board->ray.perpwalldist \
						* board->ray.raydirx;
	board->t.wallx -= floor((board->t.wallx));
}

void	ft_get_texture_adress(t_board *board)
{
	board->texture[0].addr = (int *)mlx_get_data_addr(board->texture[0].img,
			&board->texture[0].bits_per_pixel,
			&board->texture[0].line_length, &board->texture[0].endian);
	board->texture[1].addr = (int *)mlx_get_data_addr(board->texture[1].img,
			&board->texture[1].bits_per_pixel,
			&board->texture[1].line_length, &board->texture[1].endian);
	board->texture[2].addr = (int *)mlx_get_data_addr(board->texture[2].img,
			&board->texture[2].bits_per_pixel,
			&board->texture[2].line_length, &board->texture[2].endian);
	board->texture[3].addr = (int *)mlx_get_data_addr(board->texture[3].img,
			&board->texture[3].bits_per_pixel,
			&board->texture[3].line_length, &board->texture[3].endian);
}

void	ft_get_texture(t_board *board)
{
	board->texture[0].img = mlx_xpm_file_to_image(board->mlx, board->no,
			&(board->texture[0].width), &(board->texture[0].height));
	board->texture[1].img = mlx_xpm_file_to_image(board->mlx, board->so,
			&(board->texture[1].width), &(board->texture[1].height));
	board->texture[2].img = mlx_xpm_file_to_image(board->mlx, board->we,
			&(board->texture[2].width), &(board->texture[2].height));
	board->texture[3].img = mlx_xpm_file_to_image(board->mlx, board->ea,
			&(board->texture[3].width), &(board->texture[3].height));
	if (!(board->texture[0].img))
		ft_error(board, "Texture NO\n");
	if (!(board->texture[1].img))
		ft_error(board, "Texture SO\n");
	if (!(board->texture[2].img))
		ft_error(board, "Texture WE\n");
	if (!(board->texture[3].img))
		ft_error(board, "Texture EA\n");
	ft_get_texture_adress(board);
}

void	ft_draw_texture(t_board *board, int x, int y)
{
	y = board->ray.drawstart - 1;
	ft_init_texture(board);
	board->t.step = 1.0 * board->texture[0].height / board->ray.lineheight;
	board->t.texx = (int)(board->t.wallx * (double)board->texture
		[board->t.texdir].width);
	if (board->ray.side == 0 && board->ray.raydirx > 0)
		board->t.texx = board->texture[board->t.texdir].width - \
			board->t.texx - 1;
	if (board->ray.side == 1 && board->ray.raydiry < 0)
		board->t.texx = board->texture[board->t.texdir].width - \
			board->t.texx - 1;
	board->t.texpos = (board->ray.drawstart - board->ry / 2 + \
			board->ray.lineheight / 2) * board->t.step;
	while (++y <= board->ray.drawend)
	{
		board->t.texy = (int)board->t.texpos & \
			(board->texture[board->t.texdir].height - 1);
		board->t.texpos += board->t.step;
		if (y < board->ry && x < board->rx)
			board->addr[y * board->line_length / 4 + x] = \
				board->texture[board->t.texdir].addr[board->t.texy * \
				board->texture[board->t.texdir].line_length / 4 + \
				board->t.texx];
	}
}
