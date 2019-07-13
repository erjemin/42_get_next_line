/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mretha <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 19:42:32 by mretha            #+#    #+#             */
/*   Updated: 2019/05/02 21:09:50 by mretha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*result;
	char	*dup;
	size_t	tot_len;

	if (!s)
		return (NULL);
	while (*s && ft_isspace(*s))
		s++;
	dup = (char *)(s + ft_strlen(s));
	while (*s && (*dup == '\0' || ft_isspace(*dup)))
		dup--;
	tot_len = dup - s + 1;
	if ((result = ft_strnew(tot_len)))
	{
		dup = result;
		while (tot_len--)
			*dup++ = *s++;
		return (result);
	}
	return (NULL);
}
