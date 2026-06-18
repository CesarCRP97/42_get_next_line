NAME = get_next_line

CC = cc
CFLAGS = -Wall -Wextra -Werror

BUFFER_SIZE = 42
BUFFLAGS = -D BUFFER_SIZE=$(BUFFER_SIZE)

AR = ar
ARFLAGS = rcs
RM = rm -rf

HEADERS = get_next_line.h

SRC = ft_printf.c \
	ft_print_words.c \
	ft_print_numbers.c \
	ft_print_pointers.c \

OBJ = $(SRC:.c=.o)

%.o: %.c $(HEADER)
	@$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ)

clean:
	@$(RM) $(OBJ)
	@$(MAKE) -C libft clean

fclean:
	@echo "\nAction: Removing all .o files and libft.a \n"
	@$(RM) $(OBJ)
	@$(RM) $(NAME)
	@$(RM) tests
	@echo "\nSuccess: All files cleaned \n"

re: fclean all

tests: re
	@echo "\nAction: Compiling tests ... \n"
	@$(CC) $(CFLAGS) $(BUFFLAGS) -o tests main.c $(SRC)
	./tests

.PHONY: all clean fclean re
