/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mretha <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 19:42:32 by mretha            #+#    #+#             */
/*   Updated: 2019/04/10 19:43:49 by mretha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *))
{
	t_list	*result;

	if (lst && f && *f)
	{
		if ((result = ft_lstnew(lst->content, lst->content_size)))
		{
			result = (*f)(result);
			if (lst->next)
				result->next = ft_lstmap(lst->next, f);
		}
		return (result);
	}
	return (NULL);
}
