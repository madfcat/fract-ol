/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshchuki <vshchuki@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 19:13:01 by vshchuki          #+#    #+#             */
/*   Updated: 2023/10/28 19:44:45 by vshchuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;
	int	len;
	int	temp;

	c = c & 0xFF;
	temp = -1;
	if (c < 0 || c > 127)
		return ((char *) '\0');
	if (c == '\0')
	{
		len = ft_strlen(s);
		return ((char *)(&s[len]));
	}
	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			temp = i;
		i++;
	}
	if (temp != -1)
		return ((char *)(&s[temp]));
	return ((char *)('\0'));
}
