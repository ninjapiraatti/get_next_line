/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlouekar <tlouekar@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 11:09:08 by tlouekar          #+#    #+#             */
/*   Updated: 2019/11/18 15:19:18 by tlouekar         ###   ########.fr       */
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

int		youhadonejob(int fd, char *trimstr, char **strs_onejob)
{
	int		i;
	char	*temp;

	i = 0;
	temp = ft_strnew(BUFF_SIZE);
	while(trimstr[i] != '\n' && trimstr[i] != '\0')
	{
		temp[i] = trimstr[i];
		i++;
	}
	strs_onejob[fd] = ft_strjoin(strs_onejob[fd], temp);
	if (i != BUFF_SIZE)
	{	
		//printf("String was shorter than BUFF");
		strs_onejob[fd] = ft_strjoin(strs_onejob[fd], strndup(trimstr + i, BUFF_SIZE - i));
		return (0);
	}	
	//printf("\nCurrent temp: %s", strs_onejob[fd]);
	return (1);
}

int get_next_line(const int fd, char **line)
{
	char		buf[BUFF_SIZE + 1];
	static char	*strs[FD_MAX];	
	size_t		bytes;
	int			totalread;
	int			returnvalue;

	returnvalue = -1;
	totalread = 0;
	if (!line)
		return (0);
	if (!strs[fd])
		strs[fd] = "";
	while ((bytes = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[bytes] = '\0';
		//printf("\nCurrent buffer: %s", buf);
		if (youhadonejob(fd, buf, strs) == 0)
		{
			returnvalue = 1;
			break ;
		}
		//write(1, &buf, BUFF_SIZE);
		totalread += bytes;
	}
	printf("\nOutput:\n\n %s\n", strs[fd]);
	//printf("\nBytes read: %d\n", totalread);
	//write(1, strs[fd], BUFF_SIZE);
	return(returnvalue);
}
