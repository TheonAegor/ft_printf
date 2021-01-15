#include "../includes/ft_printf.h"

int main(void)
{
	int result;
	int *pres;
	int x;

/*
	result = ft_printf("hello world\n%-*.*d hi mark \n%-5.3d titiit",12,15, 123,44);
	result = printf("hello world:%d\n", 1);
*/
	//pres = &result;
	x = -1;
	result = ft_printf("%u\n", x);
	printf("%d\n", result);
	printf("%u\n", x);
}
