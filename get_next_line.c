/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlouekar <tlouekar@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 11:09:08 by tlouekar          #+#    #+#             */
/*   Updated: 2019/11/19 12:52:46 by tlouekar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "get_next_line.h"
/*
char	*youhadonejob(const char *s)
{
	char	*temp;
	int		i;
	int		len;
	int		nlfound;

	i = 0;
	nlfound = 0;
	len = 0;
	strs[fd] = ft_strjoin(strs[fd], temp);
	while (s[len] != '\0')
	{
		if (s[len] == '\n')
		{
			nlfound = 1;
			break ;
		}
		len++;
	}
	if (nlfound == 1)
	{
		if (!(temp = (char *)malloc(len * sizeof(char) + 1)))
			return (0);
		while (i < len)
		{
			temp[i] = s[i];
			i++;
		}
		return (temp);
	}
	return ((char *)s);
}
*/

int		youhadonejob(int fd, char *trimstr, char **strs_onejob, char **line)
{
	int		i;
	char	*temp;
	int		len;

	i = 0;
	len = 0;
	temp = ft_strnew(BUFF_SIZE);
	while(trimstr[i] != '\n' && trimstr[i] != '\0')
		len++;
	*line = ft_strsub(trimstr, 0, len);
	strs_onejob[fd] = ft_strjoin(strs_onejob[fd], temp);
	return (1);
}

int get_next_line(const int fd, char **line)
{
	char		buf[BUFF_SIZE + 1];
	static char	*strs[FD_MAX];	
	size_t		bytes;
	int			totalread;
	char		*temp;

	totalread = 0;
	if (!line)
		return (-1);
	if (!strs[fd])
		strs[fd] = "";
	if (strs[fd])
	{
		youhadonejob(fd, buf, strs, line); // This is now bullshit but do this if you have stuff remaining in strs
		return (1);
	}
	while ((bytes = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[bytes] = '\0';
		if (youhadonejob(fd, buf, strs, line) != 0)
			return (1);
		//printf("\nCurrent line: %s", line[fd]);
		//write(1, &buf, BUFF_SIZE);
		totalread += bytes;
		//Break somewhere
	}
	return (youhadonejob(fd, buf, strs, line));
	//printf("\nOutput:\n\n %s\n", strs[fd]);
	//printf("\nBytes read: %d\n", totalread);
	//write(1, strs[fd], BUFF_SIZE);
}
