/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strextend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mretha <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 11:31:43 by mretha            #+#    #+#             */
/*   Updated: 2019/05/09 11:31:55 by mretha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strextend(char **src, size_t addlen)
{
	char	*result;
	size_t	count;

	if (((unsigned long long)ft_strlen(*src) + \
		(unsigned long long)addlen) > SIZE_MAX || \
		!(result = ft_strnew(sizeof(char) * (ft_strlen(*src) + addlen))))
	{
		*src = NULL;
		return ;
	}
	count = 0;
	while ((*src)[count])
	{
		result[count] = (*src)[count];
		count++;
	}
	ft_strdel(src);
	*src = result;
}
