/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshchuki <vshchuki@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 19:13:01 by vshchuki          #+#    #+#             */
/*   Updated: 2023/10/28 20:01:55 by vshchuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * This issue occurs because characters in C are represented using integer 
 * values based on their ASCII codes. The ASCII character 't' has an integer 
 * value of 116. When you perform 't' + 256, you are adding 256 to this value, 
 * which results in 372. However, the ASCII character set only ranges from 0 to 
 * 127 (7-bit ASCII) or 0 to 255 (8-bit ASCII). When the integer value exceeds 
 * this range, it wraps around.
 * 
 * You may need to handle such cases in your code when working with character 
 * manipulation functions like strchr because these functions rely on valid 
 * character values within the defined character set. When you pass a character 
 * value that falls outside this range (e.g., 't' + 256), it may not behave as 
 * expected and can lead to issues like incorrect results, crashes, or undefined 
 * behavior.
 * 
 * To handle these cases, you should ensure that the input character value is 
 * within the valid range for your character manipulation functions to work 
 * correctly and safely. This typically involves checking the range of the 
 * character value before using it to avoid unexpected behavior.
 * 
 * To treat 't' + 256 as 't' in C, we can use modulo 256 (or use bitwise 
 * operations to ensure that the value stays within the range of ASCII
 * characters).
*/

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	int		len;

	c = c & 0xFF;
	if (c < 0 || c >= 127)
		return ((char *)s);
	if (c == '\0')
	{
		len = ft_strlen(s);
		return ((char *)(&s[len]));
	}
	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return ((char *)(&s[i]));
		i++;
	}
	return ((char *) 0);
}
