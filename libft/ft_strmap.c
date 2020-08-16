/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gloggins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 14:37:27 by gloggins          #+#    #+#             */
/*   Updated: 2019/11/17 14:37:28 by gloggins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*map;
	int		i;

	i = 0;
	if (!s || !f)
		return (NULL);
	if (!(map = ft_strnew(ft_strlen(s))))
		return (NULL);
	while (s[i])
	{
		map[i] = f(s[i]);
		i++;
	}
	return (map);
}
