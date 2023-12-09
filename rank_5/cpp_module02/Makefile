NAME = spell

CXX = c++ -fsanitize=address -g
CXXFLAGS = -Wall -Wextra -Werror -Wshadow -Iincludes -std=c++98
OBJS_FOLDER = base
VPATH = srcs/
RM = rm -rf

OBJS = ${SRCS:%.cpp=${OBJS_FOLDER}/%.o}
SRCS =	ASpell.cpp ATarget.cpp Warlock.cpp main.cpp Fwoosh.cpp Dummy.cpp Fireball.cpp Polymorph.cpp BrickWall.cpp TargetGenerator.cpp SpellBook.cpp


${NAME}: ${OBJS_FOLDER} ${OBJS}
	${CXX} $(CXXFLAGS) ${OBJS} -o ${NAME}

${OBJS_FOLDER}:
	mkdir -p base

${OBJS_FOLDER}/%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@ 

clean:
	${RM} ${OBJS_FOLDER}

fclean: clean
	${RM} ${NAME}

all : ${NAME}

re: fclean all

.PHONY: fclean clean re

.SILENT:
