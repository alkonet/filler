/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gloggins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 14:34:31 by gloggins          #+#    #+#             */
/*   Updated: 2019/11/17 14:34:32 by gloggins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	void		*ret;

	ret = dst;
	if (dst < src)
		while ((size_t)(dst - ret) < len)
			*(unsigned char *)dst++ = *(unsigned char *)src++;
	else
		while (len-- > 0)
			((unsigned char *)dst)[len] = ((unsigned char *)src)[len];
	return (ret);
}
