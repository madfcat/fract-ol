/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshchuki <vshchuki@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 11:20:29 by vshchuki          #+#    #+#             */
/*   Updated: 2023/10/26 11:52:57 by vshchuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	symbol;

	i = 0;
	symbol = c;
	while (i < n)
	{
		if (((unsigned char *)s)[i] == symbol)
			return ((void *)&s[i]);
		i++;
	}
	return ((void *) '\0');
}
