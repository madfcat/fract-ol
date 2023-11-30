/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshchuki <vshchuki@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 14:18:14 by vshchuki          #+#    #+#             */
/*   Updated: 2023/10/28 15:28:58 by vshchuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	needle_l;

	if (len == 0 && (!haystack || !needle))
		return ((void *)0);
	if (*needle == '\0')
		return ((char *)haystack);
	needle_l = ft_strlen(needle);
	i = 0;
	while (haystack[i] && i < len)
	{
		if (len - i < needle_l)
			break ;
		j = 0;
		while (haystack[i + j] && needle[j] && haystack[i + j] == needle[j])
			j++;
		if (needle[j] == '\0' )
			return ((char *)&haystack[i]);
		i++;
	}
	return ((void *)0);
}
