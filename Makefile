CFLAGS = -Werror -Wall -Wextra -fsanitize=address
LIBMLX = -L./minilibx/ -lmlx -framework OpenGL -framework AppKit
MLX = ./minilibx/libmlx.a
GNL = ./gnl/gnl.a
RM = rm -rf
SRC = ./display ./drawing ./hook ./main ./txt_to_arr
SRCC = $(addsuffix .c, $(SRC))
OBJ = $(addsuffix .o, $(SRC))
HEADER = ./struct.h
INCLUDES = -I./ -I./minilibx
NAME = by_lot

all: $(NAME)

$(NAME): $(OBJ) $(MLX) $(GNL)
			$(CC) $(CFLAGS) $(LIBMLX) $(GNL) $(OBJ) $(INCLUDES) -o $(NAME)

%.o: %.c $(HEADER)
			$(CC) -c $(CFLAGS) $< $(INCLUDES)

$(MLX):
			make -sC ./minilibx/

$(GNL):
			make -sC ./gnl/

clean:
			$(RM) $(NAME) $(OBJ)
			make -sC minilibx clean
			make -sC gnl clean

fclean: clean
			$(RM) $(NAME) $(MLX) $(GNL)

re:
			make fclean
			make all

.PHONY: all clean fclean re