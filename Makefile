NAME	=	so_long

FLAGS	=	-Wall -Werror -Wextra -o

CC		=	gcc

LIB		=	-L ./mlx -lmlx -lXext -lX11

INC		=	includes/so_long.h			\
			includes/get_next_line.h    \

SRC		=	main/so_long.c				\
			map_handler/create_map.c	\
			events/events.c				\
			gnl/get_next_line.c			\
			gnl/get_next_line_utils.c	\

all:	$(NAME)

$(NAME):
		$(CC) $(FLAGS) $(NAME) $(SRC) $(LIB)

clean:
		rm -rf $(NAME)