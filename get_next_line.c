/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlouekar <tlouekar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 11:09:08 by tlouekar          #+#    #+#             */
/*   Updated: 2019/11/28 09:48:56 by tlouekar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "get_next_line.h"

int		linejoiner(int fd, char **strs_joiner, char **line, int bytes)
{
	int		i;
	char	*temp;
	i = 0;
	while ((strs_joiner[fd][i] != '\0') && (strs_joiner[fd][i] != '\n'))
		i++;
	if (strs_joiner[fd][i] == '\n')
	{
		*line = ft_strsub(strs_joiner[fd], 0, i);
		temp = ft_strdup(strs_joiner[fd] + i + 1);
		ft_strdel(&strs_joiner[fd]);
		strs_joiner[fd] = temp;
		if (strs_joiner[fd][i] == '\0')
		{
			ft_strdel(&strs_joiner[fd]);
		}
		return (1);
	}
	else if (strs_joiner[fd][i] == '\0')
	{
		if (bytes == BUFF_SIZE)
			return (get_next_line(fd, line));
		*line = ft_strdup(strs_joiner[fd]);
		ft_strdel(&strs_joiner[fd]);
	}
	return (1);
}

int get_next_line(const int fd, char **line)
{

	char		buf[BUFF_SIZE + 1];
	static	char *strs[FD_MAX];
	int			bytes;
	int			i;
	char		*temp;

	i = 0;
	if ((fd < 0) || (!line) || (read(fd, buf, 0) < 0))
		return (-1);
	*line = ft_strnew(BUFF_SIZE);

	while ((!(ft_strchr(strs[fd], '\n'))) && ((bytes = read(fd, buf, BUFF_SIZE)) > 0))
	{
		buf[bytes] = '\0';
		if(strs[fd] == NULL)
			strs[fd] = ft_strnew(1);
		temp = ft_strjoin(strs[fd], buf);
		free(strs[fd]);
		strs[fd] = temp;
		if (ft_strchr(buf, '\n'))
			break ;
	}
	if ((bytes == 0 && strs[fd] == NULL) || strs[fd][0] == '\0')
		return (0);
	return (linejoiner(fd, strs, line, bytes));
}
