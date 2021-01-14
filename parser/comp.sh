#/!/bin/bash

cd ../libft/; make && cp libft.a ../parser/ && cp libft.h ../includes/
cd -
gcc main.c ft_parser.c -L. -lft ../includes/libft.a
./a.out
