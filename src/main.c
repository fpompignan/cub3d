/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: douattar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 20:07:27 by douattar          #+#    #+#             */
/*   Updated: 2022/10/20 12:31:20 by fassier-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "wolf.h"

int	main(int argc, char **argv)
{
	t_parsing	*info;
	t_board		board;

	info = parse(argc, argv);
	if (info == NULL)
		return (1);
	init_board(&board, info);
	get_mapss(&board, info);
	init_player(&board);
	init_window(&board);
	init_ray(&board);
	free_struct(info);
	ft_get_texture(&board);
	board.img = mlx_new_image(board.mlx, board.rx, board.ry);
	board.addr = (int *)mlx_get_data_addr(board.img, &board.bpp,
			&board.line_length, &board.endian);
	mlx_hook(board.win, 33, 1L << 17, ft_exit, &board);
	mlx_hook(board.win, 2, 1L << 0, ft_key_press, &board);
	mlx_loop_hook(board.mlx, ft_raycasting, &board);
	mlx_hook(board.win, 3, 1L << 1, ft_key_release, &board);
	mlx_loop(board.mlx);
	return (0);
}
