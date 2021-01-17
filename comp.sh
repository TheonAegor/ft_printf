#/!/bin/bash

#FLAG=-Wall -Wextra -Werror 

rm a.out
make
gcc main.c libftprintf.a
./a.out
