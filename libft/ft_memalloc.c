/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mretha <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/28 15:01:22 by mretha            #+#    #+#             */
/*   Updated: 2019/04/28 15:03:25 by mretha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void		*result;

	if (!(result = (void *)malloc(size)))
		return (NULL);
	while (size)
		*((char *)result + --size) = '\0';
	return (result);
}
