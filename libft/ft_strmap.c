/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mretha <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 18:46:29 by mretha            #+#    #+#             */
/*   Updated: 2019/04/28 14:32:09 by mretha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
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
		dub = result;
		while (*s)
			*dub++ = f(*s++);
		*dub = '\0';
		return (result);
	}
	return (NULL);
}
