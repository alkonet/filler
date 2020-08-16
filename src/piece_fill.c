/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piece_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gloggins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 16:36:05 by gloggins          #+#    #+#             */
/*   Updated: 2020/03/11 16:36:07 by gloggins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

/*
**	rermembers index of the upcoming tetrimino in its map
*/

int		fill_index(t_piece *piece)
{
	int i;
	int j;

	i = -1;
	while (++i < piece->height)
	{
		j = -1;
		while (++j < piece->width)
			if (piece->content[i][j] == '*')
			{
				piece->h_index = i;
				piece->w_index = j;
				return (0);
			}
	}
	return (0);
}

/*
**	takes H and W of the coming tetrimino
*/

int		fill_metadata(t_piece *piece)
{
	char	*line;
	int		i;

	if (get_next_line(0, &line) < 0)
		return (0);
	i = 0;
	while (!ft_isdigit(line[i]))
		i++;
	piece->height = ft_atoi(&line[i]);
	while (ft_isdigit(line[i]))
		i++;
	piece->width = ft_atoi(&line[i]);
	return (TRUE);
}

/*
**	here we are looking for the piece coming from filler_vm
*/

int		fill_piece(t_piece *piece)
{
	char	*line;
	int		i;

	if (!(fill_metadata(piece)))
		return (0);
	if (!(piece->content = init_map(piece->height)))
		return (0);
	i = 0;
	while (i < piece->height)
	{
		if (get_next_line(0, &line) <= 0)
			return (0);
		piece->content[i] = ft_strdup(line);
		free(line);
		i++;
	}
	fill_index(piece);
	return (TRUE);
}
