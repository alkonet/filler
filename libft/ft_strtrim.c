/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gloggins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 14:53:10 by gloggins          #+#    #+#             */
/*   Updated: 2019/11/17 14:53:13 by gloggins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*trim;
	size_t	len;

	if (!s)
		return (NULL);
	while (*s == ' ' || *s == '\t' || *s == '\n')
		s++;
	if (!*s)
		return (ft_strnew(0));
	len = ft_strlen(s);
	len--;
	while (s[len] == ' ' || s[len] == '\t' || s[len] == '\n')
		len--;
	if (!(trim = ft_strnew(len + 1)))
		return (NULL);
	while (len + 1)
	{
		trim[len] = s[len];
		len--;
	}
	return (trim);
}
