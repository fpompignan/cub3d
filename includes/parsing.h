/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: douattar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 20:47:13 by douattar          #+#    #+#             */
/*   Updated: 2022/10/13 15:06:09 by douattar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "cub3d.h"

# define END_FILL 0
# define CONTINUE_FILL 1
# define ERROR_FILL 2

// List of all error possible during the parsing
typedef enum PARSING_ERROR {
	ARGUMENTS_NUMBER,
	INVALID_EXTENSION,
	EXIST_FILE,
	INCORRECT_LINE,
	WRONG_ORDER,
	NOT_ALL_ELEMENTS,
	DOUBLE_ELEMENTS
}	t_error_type;

t_parsing	*parse(int argc, char **argv);
int			parsing_error(t_error_type type);
int			extract_info(t_parsing *res, char *filename);
int			color_variable(t_parsing *res, char *file, int i);
int			cardinal_variable(t_parsing *res, char *file, int i);

int			complete_map(t_parsing *res, int fd, char *first);
int			little_check(const t_parsing *res, unsigned int i, unsigned int j);
#endif
