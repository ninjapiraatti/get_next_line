# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tlouekar <tlouekar@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/09 18:39:23 by tlouekar          #+#    #+#              #
#    Updated: 2019/11/11 15:16:31 by tlouekar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# All this is not working #

SRCS = get_next_line.c

CFLAGS = -Wall -Wextra -Werror

EXE = a.out

MAIN = main.c

LIB = libft/libft.a

all: 
	gcc $(CFLAGS) $(MAIN) $(LIB) -o $(EXE)

debug: 
	gcc -g $(CFLAGS) $(MAIN) $(LIB) -o $(EXE)

norm:
	norminette $(SRCS)

clean:
	rm -f $(EXE)
	
re: clean all
