/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_power.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gloggins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 11:27:13 by gloggins          #+#    #+#             */
/*   Updated: 2019/11/22 11:36:49 by gloggins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_power(int n, int exp)
{
	if (exp < 0)
		return (0);
	else if (exp == 1)
		return (n);
	else
		return (n * (ft_power(n, exp - 1)));
}