/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gloggins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 17:40:33 by gloggins          #+#    #+#             */
/*   Updated: 2020/03/13 17:40:34 by gloggins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

/*
**	frees the map content and piece content
*/

void	free_all(t_map *map, t_piece *piece)
{
	int i;

	if (map)
	{
		i = 0;
		while (i <= map->height)
			free(map->content[i++]);
		free(map->content);
		ft_bzero(map, sizeof(t_map));
	}
	if (piece)
	{
		i = 0;
		while (i <= piece->height)
			free(piece->content[i++]);
		free(piece->content);
		ft_bzero(piece, sizeof(t_piece));
	}
}

void	free_coor(int **coor)
{
	int i;
	int n;

	i = 0;
	n = coor[0][0];
	if (coor)
	{
		while (i <= n && coor[i])
			free(coor[i++]);
		free(coor);
	}
}
