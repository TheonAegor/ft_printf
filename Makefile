NAME = libftprintf.a
SRC := $(wildcard *.c)
OBJ := $(addsuffix .o, $(basename $(notdir $(SRC))))
CC := gcc
FLAGS := -Wall -Wextra -Werror
OPTIONS = -I ./
$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(OPTIONS) -o $(NAME) $^
all:	$(NAME)
%.o:	%.c %.h
	$(CC) $(FLAG) -c -o $@ $<
clean:
	rm -rf $(OBJ)
fclean: clean
	rm -rf $(NAME)
re: fclean all

dolib: 
	cd libft && $(MAKE) && cp libft.a ../includes && cp libft.h ../includes
.PHONY:
	all, clean, fclean, re
