/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_coord.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gloggins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 16:46:40 by gloggins          #+#    #+#             */
/*   Updated: 2020/03/11 16:46:41 by gloggins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

int		compare(int *c1, int *c2)
{
	return (c1[2] > c2[2]);
}

int		**sort_coor(int **v_coor)
{
	int i;
	int *tmp;

	i = 1;
	while (i < v_coor[0][0])
	{
		if (compare(v_coor[i], v_coor[i + 1]))
		{
			tmp = v_coor[i];
			v_coor[i] = v_coor[i + 1];
			v_coor[i + 1] = tmp;
			i = 1;
		}
		else
			i++;
	}
	return (v_coor);
}

int		**sorted_coor(t_map map, t_piece piece, char symbol)
{
	int **v_coor;
	int **p_coor;
	int	i;

	if (!(v_coor = get_valid_coor(map, piece, symbol)) || !v_coor[0][0])
		return (NULL);
	if (!(p_coor = get_player_coor(map, symbol == 'O' ? 'X' : 'O')))
		return (NULL);
	i = 0;
	while (++i <= v_coor[0][0])
		v_coor[i][2] = enemy_distance(map, piece, p_coor, v_coor[i]);
	free_coor(p_coor);
	return (sort_coor(v_coor));
}
