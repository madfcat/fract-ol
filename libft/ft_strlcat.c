/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshchuki <vshchuki@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 16:35:58 by vshchuki          #+#    #+#             */
/*   Updated: 2023/10/28 17:45:14 by vshchuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	dst_l;
	size_t	src_l;

	src_l = ft_strlen(src);
	if (!dst && dstsize == 0)
		return (src_l);
	dst_l = ft_strlen(dst);
	if (dstsize <= dst_l)
		return (src_l + dstsize);
	i = 0;
	while (src[i] && dst_l + i + 1 < dstsize)
	{
		dst[dst_l + i] = src[i];
		i++;
	}
	dst[dst_l + i] = '\0';
	return (dst_l + src_l);
}
