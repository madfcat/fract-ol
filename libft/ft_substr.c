/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshchuki <vshchuki@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 17:54:06 by vshchuki          #+#    #+#             */
/*   Updated: 2023/11/03 15:06:42 by vshchuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub_s;
	size_t	s_size;
	size_t	i;

	if (s)
	{
		s_size = ft_strlen(s);
		if (len > (size_t) - 1 - start)
			len = (size_t) - 1 - start;
		if (len > s_size - start)
			len = s_size - start;
		else if (start >= s_size)
			len = 0;
		sub_s = (char *)malloc((len + 1) * sizeof(char));
		if (!sub_s)
			return ((void *)0);
		sub_s[len] = '\0';
		s += start;
		i = -1;
		while (++i < len)
			sub_s[i] = s[i];
		return (sub_s);
	}
	return ((char *)0);
}
