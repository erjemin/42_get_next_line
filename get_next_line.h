/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mretha <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 21:37:27 by mretha            #+#    #+#             */
/*   Updated: 2019/05/15 22:37:24 by mretha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 10000000

# include <fcntl.h>
# include "libft/libft.h"

typedef struct	s_buff
{
	int			ndx_fd;
	size_t		cursor;
	char		*buf;
	size_t		len;
}				t_buff;

int				get_next_line(int fd, char **line);

#endif
