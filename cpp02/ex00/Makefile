# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amitcul <amitcul@student.42porto.com>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/16 11:02:30 by amitcul           #+#    #+#              #
#    Updated: 2023/06/05 21:23:21 by amitcul          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	fixed

CXX		=	g++
CXXFLAGS	=	-Wall -Wextra -Werror -pedantic
RM		=	rm -f

HEADER = Fixed.h

SRCS = main.cpp Fixed.cpp

vpath %.cpp .

OBJ_DIR = ./obj/

OBJS = $(patsubst %.cpp, $(OBJ_DIR)%.o, $(SRCS))

all:
	$(MAKE) $(NAME)

$(OBJS): $(OBJ_DIR)%.o: %.cpp $(HEADER)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(NAME): $(OBJ_DIR) $(OBJS)
	echo $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $@

$(OBJ_DIR):
	mkdir $@

clean : clean
	$(RM) $(NAME)

fclean : clean
	$(RM) -R $(OBJ_DIR)
	$(RM) $(NAME)

sre : fclean
	all