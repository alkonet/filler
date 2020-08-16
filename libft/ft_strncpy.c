/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gloggins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 14:50:46 by gloggins          #+#    #+#             */
/*   Updated: 2019/11/17 14:50:47 by gloggins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	char *tmp;

	tmp = (char *)dest;
	while (n)
	{
		if (*src)
			*tmp++ = *src++;
		else
			*tmp++ = '\0';
		n--;
	}
	return (dest);
}
