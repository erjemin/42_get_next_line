/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mretha <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 19:42:32 by mretha            #+#    #+#             */
/*   Updated: 2019/05/02 14:01:52 by mretha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t	i1;
	size_t	i2;

	i1 = 0;
	i2 = 0;
	while (haystack[i1] && needle[i2])
		if (haystack[i1++] != needle[i2++])
		{
			i1 -= i2 - 1;
			i2 = 0;
		}
	if (!needle[i2])
		return ((char *)haystack + i1 - i2);
	return (NULL);
}
