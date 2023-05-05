/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fassier- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 11:31:22 by fassier-          #+#    #+#             */
/*   Updated: 2022/10/20 16:03:55 by fassier-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF_H
# define WOLF_H

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <math.h>
# include "cub3d.h"

# include <X11/keysym.h>
# include <X11/X.h>
# include "mlx.h"

# define FORWARD 119
# define BACK 115
# define LEFT 97
# define RIGHT 100
# define ROTATE_LEFT 65361
# define ROTATE_RIGHT 65363
# define ESC	65307
# define NORTH 2
# define SOUTH 4
# define WEST 5
# define EAST 3

typedef struct s_ray
{
	double	posx;
	double	posy;
	double	dirx;
	double	diry;
	double	planex;
	double	planey;
	int		x;
	double	camerax;
	double	raydirx;
	double	raydiry;
	int		mapx;
	int		mapy;
	double	sidedistx;
	double	sidedisty;
	double	deltadistx;
	double	deltadisty;
	double	perpwalldist;
	int		stepx;
	int		stepy;
	int		hit;
	int		side;
	int		lineheight;
	int		drawstart;
	int		drawend;
	double	movespeed;
	double	rotspeed;
}	t_ray;

typedef struct s_texture
{
	int		texdir;
	double	wallx;
	int		texx;
	int		texy;
	double	step;
	double	texpos;
}	t_texture;

typedef struct s_data
{
	void			*img;
	int				*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
	int				width;
	int				height;
}		t_data;

typedef struct s_board
{
	char		*no;
	char		*so;
	char		*we;
	char		*ea;
	int			sol;
	int			plafond;
	int			width;
	int			height;
	int			forward;
	int			back;
	int			left;
	int			right;
	int			r_left;
	int			r_right;
	char		**map;
	int			**maps;
	int			start_i;
	int			start_j;
	char		start_direction;
	void		*mlx;
	void		*win;
	int			rx;
	int			ry;
	int			*addr;
	int			bpp;
	int			line_length;
	int			endian;
	void		*img;
	t_texture	t;	
	t_ray		ray;
	t_data		texture[4];
}	t_board;

//-------config_board_1---------
void	init_board(t_board *board, t_parsing *info);
void	init_player(t_board *board);
int		init_window(t_board *board);
void	init_ray(t_board *board);

//---------exit------------
void	exit_wolf(t_board *board);
void	free_array(char **array);

//-------get_maps--------------------
void	get_mapss(t_board *board, t_parsing *info);
void	copy_map(t_board *board, t_parsing *info);
void	copy_texture_cardinal(t_board *board, t_parsing *info);
//-------textures-----------------
void	ft_error(t_board *board, char *str);
void	ft_init_texture(t_board *board);
void	ft_get_texture_adress(t_board *board);
void	ft_get_texture(t_board *board);
void	ft_draw_texture(t_board *board, int x, int y);

//---------exit2--------------------
int		ft_exit(t_board *board);

//---------key_press_release-------------
int		ft_key_press(int keycode, t_board *board);
int		ft_key_release(int keycode, t_board *board);

//---------------move------------------
void	ft_forward_back(t_board *board);
void	ft_left_right(t_board *board);
void	ft_rotate(t_board *board);

//------------raycasting----------------
int		ft_raycasting(t_board *board);

//--------raycasting_utils-------------
void	calculate_distance_projected(t_board *board);
void	calculate_lowest_and_highest_pixel_to_fill(t_board *board);
void	ft_init_texture_image(t_board *board);

#endif
