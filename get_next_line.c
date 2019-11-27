/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlouekar <tlouekar@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 11:09:08 by tlouekar          #+#    #+#             */
/*   Updated: 2019/11/27 21:04:06 by tlouekar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "get_next_line.h"
/*
int		returnhandler(int fd, char **strs_handler, char **line)
{
	// Returnhandler is supposed to write the stuff before \n to *line, then write the rest if needed.
	// Return 1, 0, or -1 (when -1 though?)
	// After you find \n, you also have to check if the rest of the buffer has \0 before end?
	int		i;

	i = 0;
	while (strs_handler[fd][i] != '\n')
		i++;
	if (!(*line = ft_strsub(strs_handler[fd], 0, i)))
		return (-1);
	if (!(strs_handler[fd] = ft_strdup(strs_handler[fd] + i + 1)))
		return (-1);
	return (1);
}
*/

int		linejoiner(int fd, char *buffstr, char **strs_joiner, char **line)
{
	int		i;
	char	*temp;

	i = 0;
	if ((buffstr[0] == '\0') && (!strs_joiner[fd]))
		return (0);
	//*line = ft_strjoin(*line, strs_joiner[fd]);
	strs_joiner[fd] = ft_strnew(BUFF_SIZE);
	while(buffstr[i] != '\0')
	{
		if (buffstr[i] == '\n')
		{
			*line = ft_strjoin(*line, ft_strsub(buffstr, 0, i)); // Joining not necessary, line empty at this point?
			temp = ft_strdup(buffstr + i + 1);
			strs_joiner[fd] = ft_strjoin(strs_joiner[fd], temp);
			ft_strdel(&temp);
			return (0);
		}
		i++;
	}
	if (i == BUFF_SIZE)
	{
		*line = ft_strjoin(*line, ft_strsub(buffstr, 0, i));
		return (1);
	}
	*line = ft_strjoin(*line, ft_strsub(buffstr, 0, i));
	return (1);
}

int get_next_line(const int fd, char **line)
{
	// Ok, so here's the problem. The last part after last \n doesn't go into *line
	// at any point because the returnhandler doesn't find \n and it doesn't even go
	// into the read loop.
	
	char		buf[BUFF_SIZE + 1];
	static char *strs[FD_MAX];	
	int			bytes;
	int			i;
	char		*temp;

	i = 0;
	if ((fd < 0) || (!line) || (read(fd, buf, 0) < 0))
		return (-1);
	*line = ft_strnew(BUFF_SIZE); // How to error check before this, is it needed?
	//if (ft_strchr(strs[fd], '\n')) // Use returnhandler if you find newline before /0
	//	return (returnhandler(fd, strs, line)); // returns 1, 0 or -1. When does it return -1?
	while ((!(ft_strchr(strs[fd], '\n'))) && ((bytes = read(fd, buf, BUFF_SIZE)) > 0))
	{
		buf[bytes] = '\0';
		//returnvalue = linejoiner(fd, buf, strs, line);
		// 0  = newline found
		// 1  = no newline, got to end of buffer
		// -1 = \0 found
		/*if (returnvalue == -1)
		{
			ft_strdel(&strs[fd]);
			return (0);
		}
		if (returnvalue == 0)
			return (1);*/
		while ((buf[i] != '\0') && (buf[i] != '\n'))
			i++;
		if (i == BUFF_SIZE)
			*line = ft_strjoin(*line, buf);
		else
		{
			*line = ft_strjoin(*line, ft_strsub(buf, 0, i));
			if (buf[i] == '\n')
			{
				temp = ft_strdup(buf + i + 2);
				strs[fd] = ft_strdup(temp);
			}
			return (1);
		}
	}
	return (linejoiner(fd, buf, strs, line));
}
