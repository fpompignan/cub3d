/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: douattar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 20:46:29 by douattar          #+#    #+#             */
/*   Updated: 2022/10/20 15:15:25 by douattar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct s_map {
	char			*line;
	struct s_map	*next;
}	t_map;

typedef struct s_parsing {
	char			*north;
	char			*south;
	char			*west;
	char			*east;
	int				sol;
	int				plafond;
	unsigned int	width;
	unsigned int	length;
	char			**map;
}	t_parsing;
#endif
