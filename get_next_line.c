/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlouekar <tlouekar@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 11:09:08 by tlouekar          #+#    #+#             */
/*   Updated: 2019/11/12 20:01:06 by tlouekar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "get_next_line.h"

char	*setline(int fd, char *trimstr, char **line)
{
	/*char	*temp;

	temp = ft_strnew(BUFF_SIZE);
	temp = ft_strjoin(temp, trimstr);*/
	line[fd] = ft_strjoin(line[fd], ft_strtrim(trimstr));
	return (line[fd]);
}

int get_next_line(const int fd, char **line)
{
	char	buf[BUFF_SIZE + 1];
	size_t	bytes;
	int		totalread;
	char	*temp;

	line[fd] = "";
	totalread = 0;
	while ((bytes = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[bytes] = '\0';
		setline(fd, buf, line);
		//printf("\nCurrent buffer: %s", buf);
		if ((temp = setline(fd, buf, line)) == 0)
		{
			break ;
		}
		//write(1, &buf, BUFF_SIZE);
		totalread += bytes;
	}
	printf("\nOutput:\n\n %s\n", line[fd]);
	printf("\nBytes read: %d\n", totalread);
	write(1, line[fd], BUFF_SIZE);
	return(fd);
}
