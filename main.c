#include "./includes/ft_printf.h"

int main(void)
{
	int result;
	int *pres;
	int x;

	result = 0;
/*
	result = ft_printf("hello world\n%-*.*d hi mark \n%-5.3d titiit",12,15, 123,44);
	result = printf("hello world:%d\n", 1);
*/
	pres = &result;

	x = 214748;
	result = ft_printf("hello%.50s\n%d%x%c", "crazy", x,x, 'X');
	printf("mine:%d\n\n", result);
	result = printf("hello%.50s\n%d%x%c", "crazy", x,x, 'X');
	printf("original:%d\n", result);
	printf("La-La%%%d\n", 12);
	ft_printf("hello");

}
