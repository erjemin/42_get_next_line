/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mretha <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/28 14:49:42 by mretha            #+#    #+#             */
/*   Updated: 2019/04/28 16:33:20 by mretha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;

	if (n && dest - src)
		if (dest > src)
			while (n--)
				*((unsigned char *)dest + n) = *((unsigned char *)src + n);
		else
		{
			i = 0;
			while (i < n)
			{
				*((unsigned char *)dest + i) = *((unsigned char *)src + i);
				i++;
			}
		}
	else
		;
	return (dest);
}
