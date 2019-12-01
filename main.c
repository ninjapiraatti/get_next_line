/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlouekar <tlouekar@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 10:48:15 by tlouekar          #+#    #+#             */
/*   Updated: 2019/12/01 12:22:19 by tlouekar         ###   ########.fr       */
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
	char		*line;
	int			linecount;
	int			i;
	int			countdown;
	char		anykey[59] = "\033[1;32m-----------------------------\nPress enter.\n\n\033[0m";

	i = 1;
	linecount = 0;
	countdown = 2;

	printf("\n\nPrinting up to %d lines from files, swapping fd in between. I hope you remembered to enter some as arguments..\n\n", countdown + 1);
	printf("%s", anykey);
	getchar();
	while (i < argc)
	{
		fd = open(argv[i], O_RDONLY);
		i++;
	}
	while (countdown > 0)
	{
		fd++;
		if (fd > argc + 1)
			fd = 3;
		while (get_next_line(fd, &line) == 1)
		{
			linecount++;
			ft_putstr(line);
			ft_putchar('\n');
			free(line);
			printf("%s", anykey);
			getchar();
			if (fd < argc + 1)
				fd++;
			else
				fd = 3;	
		}
		close(fd);
		countdown--;
	}
	line = NULL;
	printf("\n\nOn the next part you should only see -1. \n\n");
	printf("%s", anykey);
	getchar();
	ft_putnbr(get_next_line(1, NULL));
	ft_putnbr(get_next_line(0, NULL));
	ft_putnbr(get_next_line(1000, NULL));
	ft_putnbr(get_next_line(-1, NULL));

	ft_putnbr(get_next_line(1000, &line));
	ft_putnbr(get_next_line(-1, &line));
	ft_putnbr(get_next_line(-1000, &line));

	ft_putnbr(get_next_line(42, &line));
	ft_putchar('\n');

	printf("\n\nOk, moving on to the input. CTRL-D to exit.\n\n");
	while (get_next_line(0, &line) == 1)
	{
		ft_putstr(line);
		ft_putchar('\n');
		free(line);
	}
	printf("%s", anykey);
	getchar();

	printf("\n\nAnd last, the basic tests.\n\n");
	printf("%s", anykey);
	getchar();
	//printf("Return value: %d, File descriptor: %d, Argc count: %d, Lines read: %d\n", returnvalue, fd, argc - 1, linecount);	
	return (0);
}
