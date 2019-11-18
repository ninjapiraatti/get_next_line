/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlouekar <tlouekar@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 10:48:15 by tlouekar          #+#    #+#             */
/*   Updated: 2019/11/18 15:13:05 by tlouekar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.c"
#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include "libft/libft.h"

int		main(int argc, char **argv)
{
	int			fd;
	int			linecount;

	linecount = 0;
	fd = open(argv[1], O_RDONLY);
	//printf("%s\n", lines[0]);

	if(fd == -1)
		write(1, "No file.", 8);
	while (get_next_line(fd, argv) == 1)
		linecount++;
	printf("File descriptor: %d, Files read: %d, Lines read: %d\n", fd, argc - 1, linecount);
	return (0);
}