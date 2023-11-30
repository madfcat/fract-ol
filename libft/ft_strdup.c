/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshchuki <vshchuki@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 15:55:17 by vshchuki          #+#    #+#             */
/*   Updated: 2023/11/14 14:01:10 by vshchuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strcpy(char *dst, const char *src)
{
	char	*dst_copy;

	dst_copy = dst;
	while (*src)
	{
		*dst_copy++ = *src++;
	}
	*dst_copy = '\0';
	return (dst);
}

char	*ft_strdup(const char *s1)
{
	char	*ptr;

	ptr = (char *)malloc((ft_strlen(s1) + 1) * sizeof(char));
	if (!ptr)
		return ((char *)0);
	ft_strcpy(ptr, s1);
	return (ptr);
}
