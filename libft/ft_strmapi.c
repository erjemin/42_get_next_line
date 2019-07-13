/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mretha <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 18:49:19 by mretha            #+#    #+#             */
/*   Updated: 2019/04/28 14:30:21 by mretha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	len;
	char			*result;
	char			*dub;

	if (s && f)
	{
		len = 0;
		dub = (char *)s;
		while (*dub++)
			len++;
		if (!(result = (char *)malloc(sizeof(char) * (len + 1))))
			return (NULL);
		len = 0;
		dub = result;
		while (*s)
			*dub++ = f(len++, *s++);
		*dub = '\0';
		return (result);
	}
	return (NULL);
}
