NAME = libftprintf.a

CC = gcc

CFLAGS = -c 

SOURCES =	printf.c\
			utils_first.c\
			utils_second.c\
			parser.c\
			print_c.c\
			print_s.c\
			print_d_i.c\
			print_hex.c\
			print_u.c\
			print_p.c\
			print_percent.c\

INCLUDES = ./includes/
		
OBJECTS = $(SOURCES:.c=.o)

all: $(NAME)

$(NAME): $(OBJECTS)
	make -C libft/
	mv libft/libft.a $(NAME) 
	ar rcs $(NAME) $(OBJECTS)

.c.o:
	$(CC) $(CFLAGS) $< -o $@ -I$(INCLUDES)

clean:
	make clean -C libft
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re
