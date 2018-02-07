# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acottier <acottier@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/13 09:21:32 by acottier          #+#    #+#              #
#    Updated: 2018/01/14 16:27:34 by acottier         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= ft_retro

CC			= clang++
FLAGS		= -Wall -Wextra -Werror

SRC_PATH	= sources
OBJ_PATH	= objects

SRC_NAMES	= 	main.cpp \
				AEntity.cpp \
				Arena.cpp \
				Player.cpp \
				Projectile.cpp \
				Windows.cpp \
				Enemy.cpp \
				WaveManager.cpp \
				Time.cpp \
				random.cpp

OBJ_NAMES	= $(SRC_NAMES:.cpp=.o)

SRC			= $(addprefix $(SRC_PATH)/,$(SRC_NAMES))
OBJ			= $(addprefix $(OBJ_PATH)/,$(OBJ_NAMES))

.PHONY: all re clean fclean

all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(FLAGS) $^ -o $@ -lncurses #-fsanitize=address

$(OBJ_PATH)/%.o : $(SRC_PATH)/%.cpp
	mkdir -p $(OBJ_PATH) && $(CC) $(FLAGS) $< -c -o $@

clean :
	rm -rf $(OBJ_PATH)

fclean : clean
	rm -rf $(NAME)

re : fclean all