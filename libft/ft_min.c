/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_min.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gloggins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 11:40:19 by gloggins          #+#    #+#             */
/*   Updated: 2019/11/22 11:49:51 by gloggins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_min(int *tab, int size)
{
	int min;

	min = tab[--size];
	while (size--)
	{
		if (tab[size] < min)
			min = tab[size];
	}
	return (min);
}