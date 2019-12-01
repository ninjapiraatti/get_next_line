/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlouekar <tlouekar@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 10:48:15 by tlouekar          #+#    #+#             */
/*   Updated: 2019/12/01 11:14:39 by tlouekar         ###   ########.fr       */
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

/*
int		main(void)
{
	char		*line;
	int			ret;
	int			fd;
	int			lines;

	lines = 0;
	line = NULL;
	ret = 0;
	fd = open("test3_8buff.txt", O_RDONLY);
	// fd = open("test1_nonsense.txt", O_RDONLY);
	// fd = 42;
	// fd = open("test2_hitch.txt", O_RDONLY);
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		ft_putstr(line);
		ft_putchar('\n');
		lines++;
		ft_strdel(&line);
	}
	printf("\nNumber of lines counted: %d\n", lines);
	printf("Return value from gnl: %d\n", ret);
	printf("Simple test returns on last loop: %d\n\n", get_next_line(fd, &line));

	printf("Only -1 from now on: \n");
	ft_putchar('\n');
	ft_putnbr(get_next_line(1, NULL));
	ft_putnbr(get_next_line(0, NULL));
	ft_putnbr(get_next_line(1000, NULL));
	ft_putnbr(get_next_line(-1, NULL));

	ft_putnbr(get_next_line(1000, &line));
	ft_putnbr(get_next_line(-1, &line));
	ft_putnbr(get_next_line(-1000, &line));

	ft_putnbr(get_next_line(42, &line));
	ft_putchar('\n');

	close(fd);
	return (0);
}*/
