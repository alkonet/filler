/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heat_distance.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gloggins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 16:36:52 by gloggins          #+#    #+#             */
/*   Updated: 2020/03/11 16:36:55 by gloggins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

/*
**	counting the amount of symbols in the tetrimino
*/

int		count_symbol(t_map map, char symbol)
{
	int count;
	int i;
	int j;

	count = 0;
	i = -1;
	while (++i < MH)
	{
		j = -1;
		while (++j < MW)
			if (map.content[i][j] == symbol \
				|| map.content[i][j] == (symbol == 'O' ? 'o' : 'x'))
				count++;
	}
	return (count);
}

/*
**	returns the absolute value of a number
*/

int		abs(int n)
{
	return (n < 0 ? -n : n);
}

/*
**	counting the absolute value of distance with my abs
**	since we cant use math.h
*/

int		distance(int c1, int c2, int j1, int j2)
{
	return (abs(c1 - j1) + abs(c2 - j2));
}

int		coor_distance(t_map map, t_piece piece, int *en_c, int *c)
{
	int i;
	int j;
	int	dist;
	int tmp;

	dist = -1;
	i = -1;
	while (++i < PH)
	{
		j = -1;
		while (++j < PW)
			if (piece.content[i][j] == '*' \
				&& map.content[c[0] + i][c[1] + j] == '.')
			{
				tmp = distance(en_c[0], en_c[1], c[0] + i, c[1] + j);
				dist = (tmp < dist || dist == -1) ? tmp : dist;
			}
	}
	return (dist);
}

/*
**	counting the distance between our tetri and the closest point
**	of enemy
*/

int		enemy_distance(t_map map, t_piece piece, int **en_c, int *c)
{
	int	n;
	int	dist;
	int tmp;

	n = 0;
	dist = -1;
	while (++n < en_c[0][0] + 1)
		if ((tmp = coor_distance(map, piece, en_c[n], c)) < dist || dist == -1)
			dist = tmp;
	return (dist);
}
