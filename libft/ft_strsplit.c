/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mretha <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 20:13:39 by mretha            #+#    #+#             */
/*   Updated: 2019/04/25 20:32:51 by mretha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_count_word_by_char(char *str, char c)
{
	int								i;

	i = 0;
	while (*str)
	{
		while (*str && *str == c)
			str++;
		if (*str && *str != c)
			++i;
		while (*str && *str != c)
			++str;
	}
	return (i);
}

static char		*ft_strdup_before_char(char *str, char c)
{
	char							*result;
	char							*bub;
	int								len;

	while (*str && *str == c)
		str++;
	len = 0;
	while (str[len] && str[len] != c)
		len++;
	if (len && (result = (char *)malloc(sizeof(char) * (len + 1))))
	{
		bub = result;
		while (*str && *str != c)
			*bub++ = *str++;
		*bub = '\0';
		return (result);
	}
	return (NULL);
}

char			**ft_strsplit(char const *s, char c)
{
	char						**result;
	char						**dup;
	int							words;

	if (s)
	{
		words = ft_count_word_by_char((char *)s, c);
		if (!(result = (char **)malloc((words + 1) * sizeof(char *))))
			return (NULL);
		dup = result;
		while (words--)
		{
			while (*s && *s == c)
				s++;
			*dup = ft_strdup_before_char((char *)s, c);
			while (*s && *s != c)
				s++;
			dup++;
		}
		*dup = NULL;
		return (result);
	}
	return (NULL);
}
