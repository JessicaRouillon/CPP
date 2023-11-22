##### VARIABLES #####

CC			+= c++
CFLAGS		+= -Wall -Wextra -Werror -std=c++98
NAME		+= megaphone
SRC			+= megaphone.cpp
OBJ			+= $(SRC:.cpp=.o)
PATH_OBJ	+= objs/

##### SHELL #####

SHELL		= /usr/bin/bash

##### DISPLAY #####

RED='\033[0;31m'
GREEN='\033[1;32m'
ORANGE='\033[0;33m'
YELLOW='\033[1;33m'
BLUE='\033[1;36m'
NC='\033[0m' # No Color

##### RULES #####

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(OBJ)
	$(ECHOC) $(GREEN) "--> $(NAME) COMPILED !"$(NC)"\n\n"

$(OBJ) : $(PATH_OBJ)/%.o: %.cpp Makefile
	$(ECHO) $(ORANGE) "Compiling $<"
	mkdir -p $(PATH_OBJ)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re