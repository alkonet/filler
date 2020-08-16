/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gloggins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 14:50:32 by gloggins          #+#    #+#             */
/*   Updated: 2019/11/17 14:50:34 by gloggins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dest, const char *src, size_t n)
{
	char	*tmp;

	tmp = (char *)dest;
	while (*tmp != '\0')
		tmp++;
	while (n-- && *src)
		*tmp++ = *src++;
	*tmp = '\0';
	return (dest);
}
