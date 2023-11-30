/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshchuki <vshchuki@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 12:11:46 by vshchuki          #+#    #+#             */
/*   Updated: 2023/10/28 12:20:51 by vshchuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	char	*res;
	size_t	res_len;

	if (s && f)
	{
		res_len = ft_strlen(s);
		res = (char *)malloc((res_len + 1) * sizeof(char));
		if (!res)
			return ((char *)0);
		res[res_len] = '\0';
		i = 0;
		while (s[i])
		{
			res[i] = f(i, s[i]);
			i++;
		}
		return (res);
	}
	return ((char *)0);
}
