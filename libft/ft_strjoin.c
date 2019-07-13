/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mretha <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 19:42:32 by mretha            #+#    #+#             */
/*   Updated: 2019/05/18 18:48:31 by mretha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;
	char	*dup;
	size_t	tot_len;

	if (s1 && s2)
	{
		if (((unsigned long long)ft_strlen(s1) + \
					(unsigned long long)ft_strlen(s2) + 1) > SIZE_MAX)
			return (NULL);
		tot_len = ft_strlen(s1) + ft_strlen(s2);
		if ((result = (char *)malloc(sizeof(char) * (tot_len + 1))))
		{
			dup = result;
			while (*s1)
				*dup++ = *s1++;
			while (*s2)
				*dup++ = *s2++;
			*dup = '\0';
			return (result);
		}
	}
	return (NULL);
}
