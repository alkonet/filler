/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gloggins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 16:43:56 by gloggins          #+#    #+#             */
/*   Updated: 2020/03/11 16:43:57 by gloggins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "../libft/includes/libft.h"

# define TRUE 1
# define MH				map.height
# define MW				map.width
# define PH				piece.height
# define PW				piece.width
# define MAPCONYX		map.content[coor[0] + y][coor[1] + x]

/*
**  piece_content
**	height - of the piece
**	width - of the piece
**	**content - the given tetrimino in the given piece of map
**	h_index - the closest point of height to add in map
**	w_index - the closest point of width to add in map
*/

typedef	struct	s_piece
{
	int		height;
	int		width;
	char	**content;
	int		h_index;
	int		w_index;
}				t_piece;

/*
**  map_content
**	height
**	width
**	**content - the characters within the map now
*/

typedef	struct	s_map
{
	int		height;
	int		width;
	char	**content;
}				t_map;

/*
**  get_coordinates.c
*/

int				**get_player_coor(t_map map, char symbol);
int				is_placable(t_map map, t_piece piece, char symbol, int *coor);
int				count_if_place(t_map map, t_piece piece, char symbol);
int				**fill_valid_coor(t_map map, t_piece p, char s, int **vc);
int				**get_valid_coor(t_map map, t_piece piece, char symbol);

/*
**  heat_distance.c
*/

int				count_symbol(t_map map, char symbol);
int				abs(int n);
int				distance(int c1, int c2, int j1, int j2);
int				coor_distance(t_map map, t_piece piece, int *en_c, int *c);
int				enemy_distance(t_map map, t_piece piece, int **en_c, int *c);

/*
**	main.c
*/

void			print_coor(int c1, int c2);
char			check_player(void);

/*
**	map_fill.c
*/

char			**init_map(int height);
int				**init_coor(int nb, int distance);
int				get_map_size(t_map *map);
int				get_map_content(t_map *map);
int				fill_map(t_map *map);

/*
**	memory_free.c
*/

void			free_all(t_map *map, t_piece *piece);
void			free_coor(int **coor);

/*
** piece_fill.c
*/

int				fill_metadata(t_piece *piece);
int				fill_index(t_piece *piece);
int				fill_piece(t_piece *piece);

/*
** sort_coord.c
*/

int				compare(int *c1, int *c2);
int				**sort_coor(int **v_coor);
int				**sorted_coor(t_map map, t_piece piece, char symbol);

#endif
