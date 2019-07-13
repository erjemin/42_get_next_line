/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mretha <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 19:42:32 by mretha            #+#    #+#             */
/*   Updated: 2019/04/10 19:43:49 by mretha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t size)
{
	t_list	*result;

	if (!(result = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	result->next = NULL;
	result->content_size = 0;
	if (content)
	{
		result->content_size = size;
		if ((result->content = malloc(size)))
			while (size-- > 0)
				*(char *)(result->content + size) = *(char *)(content + size);
		else
		{
			free(result);
			return (NULL);
		}
	}
	else
		result->content = NULL;
	return (result);
}
