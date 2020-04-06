##
## EPITECH PROJECT, 2019
## Untitled (Workspace)
## File description:
## Makefile
##

SRC	=	./src/main.c			\
		./src/my_getnbr.c		\
		./src/navy.c			\
		./src/put_str.c			\
		./src/my_getnbr_base.c	\
		./src/my_put_nbr.c		\
		./src/signal.c			\
		./src/map.c				\
		./src/win_or_lose.c		\
		./src/display_map.c		\
		./src/display.c			\
		./src/get_input.c		\
		./src/game.c			\
		./src/check.c

OBJ	=	$(SRC:.c=.o)

CC	=	gcc

CPPFLAGS	=	-I include

CFLAGS	=	-W -Wextra -Wall -g

LD	= 	$(CC)

NAME	=	navy

all:	$(NAME)

$(NAME):	$(OBJ)
	$(LINK.o) $^ $(LDLIBS) $(OUTPUT_OPTION)

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re