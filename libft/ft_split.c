/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshchuki <vshchuki@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 12:08:59 by vshchuki          #+#    #+#             */
/*   Updated: 2023/11/05 12:02:33 by vshchuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count_strs(char const *s, char c, size_t *i, size_t *j)
{
	size_t	count;
	size_t	k;

	count = 0;
	k = 0;
	*i = -1;
	*j = 0;
	while (s[k])
	{
		if (s[k] != c && (k == 0 || s[k - 1] == c))
			count++;
		k++;
	}
	return (count);
}

static size_t	ft_str_len(char const *s, char c, size_t i)
{
	size_t	len;

	len = 0;
	while (s[i] != '\0' && s[i] != c)
	{
		len++;
		i++;
	}
	return (len);
}

static int	ft_fill_str(char *string, char const *s, size_t len, size_t *i)
{
	size_t	k;

	k = 0;
	while (k < len)
	{
		string[k] = s[*i];
		k++;
		if (k == len)
			break ;
		*i += 1;
	}
	return (1);
}

static char	**ft_malloc_error(char **strings, int j)
{
	while (j >= 0)
	{
		free(strings[j]);
		j--;
	}
	free(strings);
	return ((char **)0);
}

char	**ft_split(char const *s, char c)
{
	char	**strings;
	size_t	len;
	size_t	i;
	size_t	j;

	if (!s || c < 0 || c > 127)
		return ((char **)0);
	len = ft_count_strs(s, c, &i, &j);
	strings = (char **)malloc((len + 1) * sizeof(char *));
	if (!strings)
		return ((char **)0);
	strings[len] = (char *)0;
	while (s[++i])
	{
		if (s[i] != c && (i == 0 || s[i - 1] == c))
		{
			len = ft_str_len(s, c, i);
			strings[j] = (char *)malloc((len + 1) * sizeof(char));
			if (!strings[j])
				return (ft_malloc_error(strings, j));
			strings[j][len] = '\0';
			j = j + ft_fill_str(strings[j], s, len, &i);
		}
	}
	return (strings);
}
