/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gloggins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 14:51:02 by gloggins          #+#    #+#             */
/*   Updated: 2019/11/17 14:51:03 by gloggins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t n)
{
	size_t			i;
	char			*j;
	char			*k;

	if (!*needle)
		return ((char *)haystack);
	while (n-- && *haystack)
	{
		if (*haystack == *needle)
		{
			i = n;
			j = (char *)haystack + 1;
			k = (char *)needle + 1;
			while (i-- && *j && *k && *j == *k)
			{
				++j;
				++k;
			}
			if (!*k)
				return ((char *)haystack);
		}
		++haystack;
	}
	return (NULL);
}
