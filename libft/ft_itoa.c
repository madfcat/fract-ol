/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshchuki <vshchuki@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 17:51:10 by vshchuki          #+#    #+#             */
/*   Updated: 2023/10/28 14:13:13 by vshchuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Find the order of magnitude for a number*/
static int	ft_find_oom(int n)
{
	int		oom;
	long	n_long;

	n_long = n;
	oom = 0;
	if (n_long < 0)
		n_long = -n_long;
	while (n_long > 9)
	{
		n_long /= 10;
		oom++;
	}
	return (oom);
}

static long	ft_pow(int n, int oom)
{
	long	res;

	res = 1;
	while (oom > 0)
	{
		res = res * n;
		oom--;
	}
	return (res);
}

char	*ft_itoa(int n)
{
	char	*str;
	char	*res;
	int		len;
	int		oom;
	long	n_long;

	n_long = n;
	len = 11;
	oom = ft_find_oom(n_long) + 1;
	len = oom;
	if (n_long < 0)
		len++;
	res = (char *)malloc((len + 1) * sizeof(char));
	if (!res)
		return ((char *)0);
	str = res;
	*(str + len) = '\0';
	if (n_long < 0)
	{
		n_long = -n_long;
		*str++ = '-';
	}
	while (oom-- > 0)
		*str++ = n_long % ft_pow(10, oom + 1) / ft_pow(10, oom) + '0';
	return (res);
}
