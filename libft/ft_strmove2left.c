/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmove2left.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mretha <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/15 19:22:10 by mretha            #+#    #+#             */
/*   Updated: 2019/05/15 19:40:44 by mretha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strmove2left(char *dest, int position, int len)
{
	size_t	i;

	if (!position || !dest || !len)
		return ;
	i = 0;
	while (dest[position + i])
	{
		dest[i] = dest[position + i];
		i++;
	}
	while (i < (size_t)len)
		dest[i++] = '\0';
}
