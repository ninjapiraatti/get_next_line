/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlouekar <tlouekar@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 10:48:15 by tlouekar          #+#    #+#             */
/*   Updated: 2019/11/12 19:56:07 by tlouekar         ###   ########.fr       */
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
	static char	*lines[FD_MAX];
	int			fd;

	fd = open(argv[1], O_RDONLY);
	//printf("%s\n", lines[0]);

	if(fd == -1)
		write(1, "No file.", 8);
	get_next_line(fd, lines);
	printf("File descriptor: %d, Files read: %d\n", fd, argc - 1);
	return (0);
}