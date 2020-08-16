/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_coordinates.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gloggins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 16:34:38 by gloggins          #+#    #+#             */
/*   Updated: 2020/03/11 16:34:39 by gloggins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

/*
**	depending of the players number
**	looks for the next place
*/

int		**get_player_coor(t_map map, char symbol)
{
	int	**coor;
	int	i;
	int	j;
	int nb;

	if (!(coor = init_coor(count_symbol(map, symbol), 0)))
		return (NULL);
	nb = 1;
	i = -1;
	while (++i < MH)
	{
		j = -1;
		while (++j < MW)
			if (map.content[i][j] == symbol \
				|| map.content[i][j] == (symbol == 'O' ? 'o' : 'x'))
			{
				coor[nb][0] = i;
				coor[nb][1] = j;
				nb++;
			}
	}
	return (coor);
}

/*
**	looks on the map
**	if it is possible to place a new tetrimino - and goes to
**	fill_valid_coor
**	if not 0 ends the program
*/

int		is_placable(t_map map, t_piece piece, char symbol, int *coor)
{
	int	nbover;
	int	x;
	int y;

	nbover = 0;
	y = -1;
	while (++y < PH)
	{
		x = -1;
		while (++x < PW)
		{
			if (piece.content[y][x] == '*' && (coor[0] + y >= MH || \
				coor[1] + x >= MW || coor[0] + y < 0 || coor[1] + x < 0))
				return (0);
			if (piece.content[y][x] == '*' && MAPCONYX == symbol)
				nbover++;
			if (piece.content[y][x] == '*' && MAPCONYX != '.' \
				&& MAPCONYX != symbol)
				return (0);
		}
	}
	return (nbover == 1);
}

/*
**	if the tetrimino is placeble - counts it
*/

int		count_if_place(t_map map, t_piece piece, char symbol)
{
	int		i;
	int		j;
	int		count;
	int		*coor;

	i = -1 - piece.h_index;
	count = 0;
	coor = (int *)malloc(sizeof(int) * 2);
	while (i++ < MH)
	{
		j = -1 - piece.w_index;
		while (j++ < MW)
		{
			coor[0] = i;
			coor[1] = j;
			count += is_placable(map, piece, symbol, coor);
		}
	}
	free(coor);
	return (count);
}

/*
**	place the tetrimino coordinates
*/

int		**fill_valid_coor(t_map map, t_piece piece, char symbol, int **vc)
{
	int		i;
	int		j;
	int		nb;
	int		*c;

	nb = 1;
	i = -1 - piece.h_index;
	c = (int *)malloc(sizeof(int) * 2);
	while (i++ < MH)
	{
		j = -1 - piece.w_index;
		while (j++ < MW)
		{
			c[0] = i;
			c[1] = j;
			if (is_placable(map, piece, symbol, c))
			{
				vc[nb][0] = i;
				vc[nb][1] = j;
				nb++;
			}
		}
	}
	free(c);
	return (vc);
}

int		**get_valid_coor(t_map map, t_piece piece, char symbol)
{
	int		**coor;

	if (!(coor = init_coor(count_if_place(map, piece, symbol), 1)))
		return (NULL);
	return (fill_valid_coor(map, piece, symbol, coor));
}
