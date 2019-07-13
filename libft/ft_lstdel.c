/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mretha <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 19:42:32 by mretha            #+#    #+#             */
/*   Updated: 2019/04/10 19:43:49 by mretha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **lst, void (*del)(void *, size_t))
{
	t_list	*next;

	if (lst && del && *lst)
	{
		next = (*lst)->next;
		ft_lstdelone(lst, del);
		ft_lstdel(&next, del);
	}
}
