/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mretha <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 21:40:43 by mretha            #+#    #+#             */
/*   Updated: 2019/05/18 16:18:08 by mretha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

static t_buff	ft_buff_new(int fd)
{
	t_buff	new_buff2que;

	new_buff2que.buf = ft_strnew(BUFF_SIZE);
	new_buff2que.ndx_fd = fd;
	new_buff2que.cursor = BUFF_SIZE;
	new_buff2que.len = BUFF_SIZE;
	return (new_buff2que);
}

static t_buff	*ft_buff_find(t_buff *tb, int fd)
{
	ssize_t		count;

	count = -1;
	while (tb[++count].buf)
		if (tb[count].ndx_fd == fd && tb[count].buf)
			return (&tb[count]);
	return (NULL);
}

static t_buff	*ft_buff_expand(t_buff **address_buffs, int fd)
{
	ssize_t		len;
	t_buff		*buffs;

	if (!address_buffs)
		return (NULL);
	len = 0;
	while ((*address_buffs)[len].buf)
		len++;
	if (!(buffs = malloc(sizeof(t_buff) * (len + 1))))
		return (NULL);
	while (len)
	{
		buffs[len] = (*address_buffs)[len - 1];
		len--;
	}
	buffs[len] = ft_buff_new(fd);
	free(*address_buffs);
	*address_buffs = buffs;
	return (&buffs[len]);
}

static t_buff	*ft_buff_get(const int fd)
{
	static t_buff	*buffs = NULL;
	t_buff			*result;

	if (!buffs)
	{
		if (!(buffs = (t_buff *)malloc(sizeof(t_buff *))))
			return (NULL);
		buffs->buf = NULL;
		buffs->ndx_fd = 0;
	}
	if (!(result = ft_buff_find(buffs, fd)))
		result = ft_buff_expand(&buffs, fd);
	return (result);
}

int				get_next_line(const int fd, char **line)
{
	t_buff	*bf;
	size_t	len;

	if (!line || fd < 0 || read(fd, *line, (len = 0)) < 0)
		return (-1);
	bf = ft_buff_get(fd);
	if (bf->len)
		*line = ft_strnew((size_t)bf->len);
	else
		return (0);
	while (bf->len > 0 && bf->buf[bf->cursor] != '\n')
		if (bf->cursor < bf->len)
			(*line)[len++] = (bf->buf)[bf->cursor++];
		else if ((bf->len = (size_t)read(bf->ndx_fd, bf->buf, BUFF_SIZE)) > 0)
			ft_strextend(line, (size_t)bf->len + (bf->cursor = 0));
	ft_stradd(line + ((bf->buf)[bf->cursor++] = '\0'), "");
	if ((ssize_t)bf->len < 0)
		return (-1);
	return (bf->len > 0 || ft_strlen(*line) ? 1 : 0);
}
