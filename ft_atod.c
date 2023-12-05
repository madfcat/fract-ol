/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atod.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshchuki <vshchuki@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 17:02:22 by vshchuki          #+#    #+#             */
/*   Updated: 2023/12/04 18:04:58 by vshchuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractol.h"

static int	ft_find_oom(long n)
{
	int		oom;

	oom = 0;
	if (n < 0)
		n = -n;
	while (n > 9)
	{
		n /= 10;
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

static int	ft_isstrnum(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!(ft_isdigit(str[i])
				|| ((str[i] == '-' || str[i] == '+') && i == 0)))
		{
			return (0);
		}
		i++;
	}
	return (1);
}

double	ft_atod(const char *str)
{
	char	*pos;
	char	*before;
	char	*after;
	int		k;
	double	result;

	k = 1;
	pos = ft_strchr(str, '.');
	before = ft_substr(str, 0, pos - str);
	result = ft_atoi(before);
	if (!pos)
		return (result);
	after = ft_substr(&pos[1], 0, ft_strlen(&pos[1]));
	if (str[0] == '-')
		k = -1;
	result += (double)ft_atoi(after) * k
		/ (double)ft_pow(10, (ft_find_oom(ft_atoi(after))) + 1);
	if (ft_isstrnum(before) == 0)
		result = 0;
	free(before);
	free(after);
	return (result);
}

// int	main(void)
// {
// 	// printf("Output: %d\n", ft_atoi("-025"));
// 	printf("Output: %lf\n", ft_atod("-0.231"));
// 	printf("Output: %lf\n", ft_atod("-.730"));
// 	printf("Output: %lf\n", ft_atod("-23"));
// 	printf("Output: %lf\n", ft_atod("15"));
// 	printf("Output: %lf\n", ft_atod("-23.4445"));
// 	printf("Output: %lf\n", ft_atod("23.4445"));
// 	printf("Output: %lf\n", ft_atod("23.4445.fdhgfdghfd"));
// 	printf("Output: %lf\n", ft_atod("sdffsdfsd23.4445.fdhgfdghfd"));
// 	printf("Output: %lf\n", ft_atod("--23.4445.fdhgfdghfd"));
// 	printf("Output: %lf\n", ft_atod("-0.4445.fdhgfdghfd"));
// 	printf("Output: %lf\n", ft_atod("-+0.4445.fdhgfdghfd"));
// 	printf("Output: %lf\n", ft_atod(".4445.fdhgfdghfd"));
// 	return (0);
// }
