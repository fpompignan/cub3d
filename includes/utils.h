/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: douattar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 12:51:46 by douattar          #+#    #+#             */
/*   Updated: 2022/10/20 14:31:57 by douattar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H
# define BUFFER_SIZE 10

# include "cub3d.h"

int		strlen_double(char **str);
void	strfree_double(char **str);
char	**strcpy_double(char **str);

void	init_struct(t_parsing *res);
void	free_struct(t_parsing *res);

char	*ft_strcpy(char *str);
char	*get_next_line(int fd);
char	*error_return(char **rest);
int		c(char **pointer, int next);
int		cat(char *dest, char *source, long unsigned int size);

t_map	*ft_lstnew(char *content);
int		ft_lstsize(t_map *lst);
void	ft_lstadd_back(t_map **lst, t_map *new);
void	ft_lstdelone(t_map *lst);
void	ft_lstclear(t_map *lst);
int		check_struct_default(t_parsing *res);
#endif
