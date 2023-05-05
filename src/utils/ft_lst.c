/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: douattar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 17:00:19 by douattar          #+#    #+#             */
/*   Updated: 2022/10/13 11:33:22 by douattar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

t_map	*ft_lstnew(char *content)
{
	t_map	*res;

	res = (t_map *)malloc(sizeof(t_map));
	if (res == NULL)
		return (NULL);
	res->next = NULL;
	res->line = content;
	return (res);
}

int	ft_lstsize(t_map *lst)
{
	t_map	*res;
	int		i;

	if (lst == NULL)
		return (0);
	res = lst;
	i = 0;
	while (res != NULL)
	{
		res = res->next;
		i++;
	}
	return (i);
}

void	ft_lstadd_back(t_map **lst, t_map *new)
{
	t_map	*temp;

	if (lst == NULL || new == NULL)
		return ;
	temp = *lst;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = new;
	new->next = NULL;
}

void	ft_lstdelone(t_map *lst)
{
	if (lst != NULL)
	{
		if (lst->line != NULL)
			free(lst->line);
		free(lst);
	}
}

void	ft_lstclear(t_map *lst)
{
	if (lst == NULL)
		return ;
	else
		ft_lstclear(lst->next);
	ft_lstdelone(lst);
}
