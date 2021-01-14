#/!/bin/bash

rm a.out
cd ../libft/; make; cp libft.a ../base/ && cp libft.h ../includes/
cd -
gcc main.c ../parser/ft_parser.c ft_printf.c ft_copysrc.c -L. -lft ../includes/libft.a
./a.out
