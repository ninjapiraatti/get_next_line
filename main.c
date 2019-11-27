/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlouekar <tlouekar@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 10:48:15 by tlouekar          #+#    #+#             */
/*   Updated: 2019/11/27 20:40:02 by tlouekar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.c"
#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include "libft/libft.h"

/*
int		main(int argc, char **argv)
{
	int			fd;
	char		*line;
	int			linecount;
	int			returnvalue;
	int			switcher;
	int			i;
	int			countdown;
	char		*fds;

	i = 1;
	countdown =  30;
	switcher = 3;
	returnvalue = 0;
	linecount = 0;
	fds = ft_strnew(argc + 2);
	while (i < argc)
	{
		fd = open(argv[i], O_RDONLY);
		fds[fd - 3] = 48; 
		i++;
	}
	//printf("%s\n", lines[0]);
	while (countdown > 0)
	{
		while ((fds[fd - 3] == 49) && (fd < argc + 1))
			fd++;
		while (get_next_line(1000, &line) == 1)
		{
			linecount++;
			ft_putstr(line);
			ft_putchar('\n');
			free(line);
			if (fd < argc + 1)
				fd++;
			else
				fd = 3;	
		}
		fds[fd - 3] = 49;
		countdown--;
	}
	if (get_next_line(fd, &line) == -1)
	{
		returnvalue = -1;	
	}
	if (get_next_line(fd, &line) == 0)
	{
		returnvalue = 0;	
	}
	printf("Return value: %d, File descriptor: %d, Argc count: %d, Lines read: %d\n", returnvalue, fd, argc - 1, linecount);	
	return (0);
}
*/

int		main(void)
{
	char		*line;
	int			ret;
	int			fd;

	fd = open("content1.txt", O_RDONLY);
	//fd = 42;
	//fd = open("gnl7_1.txt", O_RDONLY);
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		ft_putstr(line);
		ft_putchar('\n');
		//ft_strdel(&line);
	}
	printf("\nReturn value from gnl: %d\n", ret);
	printf("Simple test returns on last line: %d\n", get_next_line(fd, &line));
	close(fd);
	return (0);
}

