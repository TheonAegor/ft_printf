#/!/bin/bash

#FLAG=-Wall -Wextra -Werror 

rm a.out
make
gcc -g main.c libftprintf.a 
./a.out
