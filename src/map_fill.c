/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_fill.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gloggins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 16:36:22 by gloggins          #+#    #+#             */
/*   Updated: 2020/03/11 16:36:23 by gloggins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

int		**init_coor(int nb, int distance)
{
	int	**coor;
	int	i;

	if (!nb)
		return (NULL);
	if (!(coor = (int **)malloc(sizeof(int *) * (nb + 1))))
		return (NULL);
	coor[0] = (int *)malloc(sizeof(int *));
	coor[0][0] = nb;
	if (nb >= 1)
	{
		i = 0;
		while (++i < nb + 1)
			if (!(coor[i] = (int *)malloc(sizeof(int) * (2 + distance))))
				return (NULL);
	}
	return (coor);
}

/*
**	looking for the first placeble index on the str
*/

int		get_map_content(t_map *map)
{
	char	*line;
	int		i;

	if (get_next_line(0, &line) < 0)
		return (0);
	free(line);
	i = 0;
	while (i < map->height)
	{
		if (get_next_line(0, &line) <= 0)
			return (0);
		map->content[i] = ft_strdup(line + 4);
		free(line);
		i++;
	}
	return (TRUE);
}

/*
**	initializing the map depending on the height
*/

char	**init_map(int height)
{
	char	**map;

	if (!(map = (char **)(malloc(sizeof(char*) * (height + 1)))))
		return (NULL);
	map[height] = NULL;
	return (map);
}

/*
** if the map is ok - takes H and W of the map
*/

int		get_map_size(t_map *map)
{
	char	*line;

	if (get_next_line(0, &line) <= 0)
		return (0);
	while (!(ft_isdigit(*line)))
		line++;
	map->height = ft_atoi(line);
	while (ft_isdigit(*line))
		line++;
	map->width = ft_atoi(line);
	return (TRUE);
}

/*
**	checking on the program mistakes
**	also filling it with parameters
*/

int		fill_map(t_map *map)
{
	if (!get_map_size(map))
		return (0);
	if (!(map->content = init_map(map->height)))
		return (0);
	if (!get_map_content(map))
		return (0);
	return (TRUE);
}
