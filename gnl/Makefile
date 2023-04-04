CFLAGS = -Wall -Wextra -Werror
AR = ar
ARFLAGS = rc
NAME = gnl.a
HEADER = get_next_line.h
RM = rm -f
SRC = get_next_line.c get_next_line_utils.c
OBJ = $(SRC:%.c=%.o)

all : $(NAME)

$(NAME) : $(OBJ)
	$(AR) $(ARFLAGS) $@ $^

%.o : %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@ -I .

clean : 
	$(RM) $(OBJ)

fclean : clean
	$(RM) $(NAME)

re :
	make fclean
	make all

.PHONY : all clean fclean re
