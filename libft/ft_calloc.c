/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshchuki <vshchuki@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 17:43:06 by vshchuki          #+#    #+#             */
/*   Updated: 2023/11/17 17:59:11 by vshchuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;
	size_t	max_size;

	max_size = (size_t)-1;
	if (count != 0 && max_size / count < size)
		return ((void *)0);
	ptr = malloc(count * size);
	if (!ptr)
		return ((void *)0);
	ft_bzero(ptr, count * size);
	return (ptr);
}
