/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mretha <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/28 14:27:35 by mretha            #+#    #+#             */
/*   Updated: 2019/05/18 17:14:09 by mretha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char		*result;

	if (((unsigned long long)size + 1) > SIZE_MAX)
		return (NULL);
	if (!(result = (char *)malloc((sizeof(char)) * ++size)))
		return (NULL);
	while (size)
		result[--size] = '\0';
	return (result);
}
