# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fabou-za <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/01 20:50:17 by fabou-za          #+#    #+#              #
#    Updated: 2023/01/02 04:19:26 by fabou-za         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Cast
CFLAGS = -Wall -Werror -Wextra -std=c++98
CC = c++

SRC_NAME = main.cpp

OBJ_NAME = $(SRC_NAME:%.cpp=%.o)

all: $(NAME)

$(NAME): $(OBJ_NAME)
	$(CC) $^ -o $@

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	rm -f $(OBJ_NAME)

fclean: clean 
	rm -rf $(NAME)

re: fclean all
