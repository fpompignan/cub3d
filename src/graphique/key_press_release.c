/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press_release.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fassier- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 14:39:29 by fassier-          #+#    #+#             */
/*   Updated: 2022/10/17 12:47:31 by douattar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int	ft_key_press(int keycode, t_board *board)
{
	if (keycode == FORWARD)
		board->forward = 1;
	if (keycode == BACK)
		board->back = 1;
	if (keycode == LEFT)
		board->left = 1;
	if (keycode == RIGHT)
		board->right = 1;
	if (keycode == ROTATE_LEFT)
		board->r_left = 1;
	if (keycode == ROTATE_RIGHT)
		board->r_right = 1;
	if (keycode == ESC)
		ft_exit(board);
	return (1);
}

int	ft_key_release(int keycode, t_board *board)
{
	if (keycode == FORWARD)
		board->forward = 0;
	if (keycode == BACK)
		board->back = 0;
	if (keycode == LEFT)
		board->left = 0;
	if (keycode == RIGHT)
		board->right = 0;
	if (keycode == ROTATE_LEFT)
		board->r_left = 0;
	if (keycode == ROTATE_RIGHT)
		board->r_right = 0;
	return (1);
}
