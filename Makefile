NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
SRC = ft_printf.c ft_outil.c
OBJ = $(SRC:.c=.o)

$(NAME): $(OBJ)
		ar rc $(NAME) $(OBJ)
%.o: %.c
		$(CC) $(CFLAGS) -o $@ -c $<

all: $(NAME)
	
clean:	
		$(RM) $(OBJ)
fclean: clean
		$(RM) $(NAME) 

re: fclean all
