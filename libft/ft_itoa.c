/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mretha <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 19:42:32 by mretha            #+#    #+#             */
/*   Updated: 2019/04/28 15:07:10 by mretha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_itoa_len(int n)
{
	int				len;
	int				pow;
	unsigned int	nn;

	pow = 1;
	len = 1;
	if (n >= 0)
		nn = n;
	else
		nn = -n * len++;
	while (nn / pow > 9 && len++)
		pow *= 10;
	return (len);
}

static void		ft_str_add_char(char *str, char c)
{
	while (*str)
		str++;
	*str = c;
}

static void		ft_uitoa(char *str, unsigned int n)
{
	if (n > 9)
		ft_uitoa(str, n / 10);
	ft_str_add_char(str, '0' + n % 10);
}

char			*ft_itoa(int n)
{
	int		len;
	char	*result;

	len = ft_itoa_len(n);
	if ((result = (char *)ft_memalloc((sizeof(char) * (len + 1)))))
	{
		if (n < 0)
		{
			ft_str_add_char(result, '-');
			ft_uitoa(result, (unsigned int)(-n));
		}
		else
			ft_uitoa(result, (unsigned int)n);
		return (result);
	}
	return (NULL);
}
