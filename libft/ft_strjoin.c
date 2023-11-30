/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshchuki <vshchuki@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 10:30:04 by vshchuki          #+#    #+#             */
/*   Updated: 2023/11/11 13:25:41 by vshchuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new_s;
	size_t	s1_len;
	size_t	s2_len;

	if (s1 && s2)
	{
		s1_len = ft_strlen(s1);
		s2_len = ft_strlen(s2);
		new_s = (char *)malloc((s1_len + s2_len + 1) * sizeof(char));
		if (!new_s)
			return ((void *)0);
		ft_strlcpy(new_s, s1, (s1_len + 1));
		ft_strlcat(new_s, s2, (s1_len + s2_len + 1));
		return (new_s);
	}
	else
	{
		if (!s1)
			return (ft_strdup(s2));
		else if (!s2)
			return (ft_strdup(s1));
	}
	return ((char *) 0);
}
