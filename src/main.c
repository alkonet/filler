/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gloggins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 16:32:59 by gloggins          #+#    #+#             */
/*   Updated: 2020/03/11 16:33:00 by gloggins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

/*
**	printing on the standart output coordinates to place
*/

void	print_coor(int c1, int c2)
{
	ft_putnbr(c1);
	ft_putchar(' ');
	ft_putnbr(c2);
	ft_putchar('\n');
}

/*
**	checking the line file and the player name
**	gives a char for the players tetriminos
*/

char	check_player(void)
{
	char	*line;
	int		i;
	char	symbol;

	if (get_next_line(0, &line) && line && ft_strlen(line) > 10 &&
			!ft_strncmp(line, "$$$ exec p", 9) &&
			(line[10] == '1' || line[10] == '2'))
	{
		i = 0;
		while (line[i] != 'p')
			i++;
		i++;
		symbol = (line[i] == '1') ? 'O' : 'X';
		free(line);
		return (symbol);
	}
	else
	{
		free(line);
		return (0);
	}
}

/*
**	enter of the program:
**	checking on major mistakes, sorts and prints on the output
*/

int		main(void)
{
	t_piece		piece;
	t_map		map;
	char		symbol;
	int			**coor;

	if (!(symbol = check_player()))
		return (0);
	while (TRUE)
	{
		if (!fill_map(&map) || !fill_piece(&piece))
			break ;
		if ((coor = sorted_coor(map, piece, symbol)))
		{
			print_coor(coor[1][0], coor[1][1]);
			free_coor(coor);
		}
		else
			print_coor(0, 0);
		free_all(&map, &piece);
	}
	return (0);
}
