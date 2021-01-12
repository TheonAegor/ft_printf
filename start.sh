arg=ft_printf.c

cd /home/taegor/school21/level0/libft_passed/libft; make && cp libft.a libft.h /home/taegor/school21/level1/ft_printf/ft_printf/
cd -
gcc $arg -L. -lft  
./a.out
