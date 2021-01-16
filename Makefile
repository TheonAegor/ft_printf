NAME = libftprintf.a

SRC :=	./base/ft_printf.c ./base/ft_copysrc.c\
		./parser/ft_parser.c\
		./processor/ft_processor.c\
		./processor/ft_find_sixteens.c\
		./processor/ft_find_tens.c\
		./processor/ft_proc_hex.c\
		./processor/ft_proc_p.c\
		./processor/ft_proc_s.c\
		./processor/ft_proc_c.c\
		./processor/ft_putnbr_u.c	

OBJ := $(SRC:.c=.o)

CC := gcc

FLAGS := -c -Wall -Wextra -Werror

OPTIONS = -I ../includes/

all:	$(NAME)

$(NAME): $(OBJ)
	make -C libft/
	cp libft/libft.a $(NAME)
	ar rcs $(NAME) $(OBJ)

.c.o:	
	$(CC) -c $< -o $@ $(OPTIONS)

clean:
	make clean -C libft
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY:
	all, clean, fclean, re
