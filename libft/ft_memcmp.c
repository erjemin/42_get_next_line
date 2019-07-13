/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mretha <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 19:27:04 by mretha            #+#    #+#             */
/*   Updated: 2019/05/01 20:14:38 by mretha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	count;

	count = 0;
	if (n && s1 != s2)
	{
		while (count < n)
			if (*((unsigned char *)s1 + count) != \
					*((unsigned char *)s2 + count))
				return ((int)(*((unsigned char *)s1 + count) - \
							*((unsigned char *)s2 + count)));
			else
				count++;
		return ((int)(*((unsigned char *)s1 + count - 1) - \
			*((unsigned char *)s2 + count - 1)));
	}
	return (0);
}
