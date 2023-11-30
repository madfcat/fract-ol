/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshchuki <vshchuki@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 17:02:22 by vshchuki          #+#    #+#             */
/*   Updated: 2023/11/14 14:37:43 by vshchuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(char c)
{
	if ((c >= 9 && c <= 13) || (c == 32))
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int					i;
	int					k;
	unsigned long long	res;
	unsigned long long	m_l;

	m_l = ((unsigned long)-1) / 2;
	i = 0;
	k = 1;
	res = 0;
	while (ft_isspace(str[i]) == 1)
		i++;
	if (str[i] == '-')
		k = -1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (ft_isdigit(str[i]))
	{
		if ((res > m_l / 10 || (str[i] > '7' && res == m_l / 10)) && k == -1)
			return (0);
		else if (res > m_l / 10 || (str[i] > '7' && res == m_l / 10))
			return (-1);
		res = res * 10 + ((unsigned long long)str[i] - '0');
		i++;
	}
	return (k * (int)res);
}
