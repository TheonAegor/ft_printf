#	include "./includes/ft_printf.h"

	enum ints {max = 2147483647, min = -2147483648, z = 0, ol = 1, simple = 234, tv = -12};
	enum chars {a = 97, A = 65, one = 49, question = 64, zer = 0}; 

int main(void)
{

	int result;
	int i = 0;
	char *zerro;
	char *str_0 = "0";
	char *str_1 = "hello";
	char *str_2 = "X";
	char *str_3 = "abcdefhgldfkgjsl;gjlsjfd;gjsflsdfg";
	char	*n = "abcdefghijklmnop";
	char	*o = "-a";
	char	*p = "-12";
	char	*q = "0";
	char	*r = "%%";
	char	*s = "-2147483648";
	char	*t = "0x12345678";
	char	*u = "-0";
	int		d = 2147483647;
	int		e = -2147483648;
	int		f = 42;
	int		g = 25;
	int		h = 4200;
	int		i2 = 8;
	int		j = -12;
	int		k = 123456789;
	int		l = 0;
	int		m = -12345678;
	zerro = NULL;
	char *strs[] = {n, o, p, q, r, s, t, u, zerro, NULL};
	char *p_str;
	enum chars arr_ch[] = {a, A, question, one, zer};
	enum chars iter;
	enum ints arr[] = {ol, z, tv, simple, max, min};
	enum ints iterator;

	printf("=============================TEST INT======================\n");	
	while (i < 6)
	{
		iterator = arr[i];
		result = ft_printf("%04d", iterator);
		printf("1)mine:%d\n", result);
		result = printf("%04d", iterator);
		printf("2)original:%d\n\n", result);
		i++;
	}
	printf("=============================TEST HEX======================\n");	
	i = 0;

	while (i < 5)
	{
		iterator = arr[i];
		result = ft_printf("%u, %*x, %*X\t",-12, -1, iterator, -1, iterator);
		printf("1)mine:%d\n", result);
		result = printf("%u, %*x, %*X\t",-12, -1, iterator, -1, iterator);
		printf("2)original:%d\n\n", result);
		i++;
	}

	printf("=============================TEST UNSIGNED======================\n");	
	i = 0;
	while (i < 5)
	{
		iterator = arr[i];
		result = ft_printf("%0c%0u\t",'a', iterator);
		printf("1)mine:%d\n", result);
		result = printf("%0c%0u\t",'a', iterator);
		printf("2)original:%d\n\n", result);
		i++;
	}
	printf("=============================TEST STRING======================\n");	
	i = 0;
	while (i < 9)
	{
		p_str = strs[i];
		result = ft_printf("%.0s", p_str);
		printf("(1)mine:%d\n", result);
		result = printf("%.0s", p_str);
		printf("(2)original:%d\n\n", result);
		i++;
	}
	printf("=============================TEST CHAR======================\n");	
	i = 0;
	while (i < 5)
	{
		iter = arr_ch[i];
		result = ft_printf("%-5c", iter);
		printf("(1)mine:%d\n", result);
		result = printf("%-5c", iter);
		printf("(2)original:%d\n\n", result);
		i++;
	}
	printf("=============================TEST POINTER======================\n");	
	i = 0;
	while (i < 5)
	{
		iterator = arr[i];
		result = ft_printf("%10p\t", &iterator);
		printf("1)mine:%d\n", result);
		result = printf("%10p\t", &iterator);
		printf("2)original:%d\n\n", result);
		i++;
	}
	printf("=============================TEST %%======================\n");	
	result = ft_printf("%5%d", 5);
	printf("1)mine:%d\n", result);
	result = printf("%5%d", 5);
	printf("2)original:%d\n\n", result);
	result = ft_printf("%-05%%d", 5);
	printf("1)mine:%d\n", result);
	result = printf("%-05%%d", 5);
	printf("2)original:%d\n\n", result);
	printf("=============================TEST MULTIPLE======================\n");	
	i = 0;
	while (i < 5)
	{
		iterator = arr[i];
		result = ft_printf("%-5.10d%d\t", iterator, 2);
		printf("1)mine:%d\n", result);
		result = printf("%-5.10d%d\t", iterator, 2);
		printf("2)original:%d\n\n", result);
		i++;
	}

	printf("=============================TEST STAR======================\n");	
	i = 0;
	while (i < 5)
	{
		iterator = arr[i];
		result = ft_printf("%*.*d\t",2,3, iterator);
		printf("1)mine:%d\n", result);
		result = printf("%*.*d\t",2,3, iterator);
		printf("2)original:%d\n\n", result);
		i++;
	}
	printf("=============================TEST MISTAKES======================\n");	
	i = 0;
	while (i < 5)
	{
		iterator = arr[i];
		result = ft_printf("%08.5x",iterator);
		printf("(1)mine:%d\n", result);
		result = printf("%08.5x",iterator);
		printf("(2)original:%d\n\n", result);
		i++;
	}
	printf("=============================TEST 0======================\n");	
	i = 0;
	while (i < 5)
	{
		iterator = arr[i];
		result = ft_printf("%.5d", iterator);
		printf("(1)mine:%d\n", result);
		result = printf("%.5d", iterator);
		printf("(2)original:%d\n\n", result);
		i++;
	}

	result = printf("%010.20c|", '-');
	printf("result:%d\n", result);
	result = ft_printf("%010.20c|", '-');
	printf("result:%d\n", result);

	result = printf("%d%0s|",1, "abcdefghijklmnop");
	printf("result:%d\n", result);
	result = ft_printf("%d%0s|",1, "abcdefghijklmnop");
	printf("result:%d\n", result);
//	result = ft_printf("%010.20s|", "hello world");
//	printf("result:%d\n", result);
/*
int		a = -4;
	int		b = 0;
	char	c = 'a';
	int		d = 2147483647;
	int		e = -2147483648;
	int		f = 42;
	int		g = 25;
	int		h = 4200;
	i = 8;
	int		j = -12;
	int		k = 123456789;
	int		l = 0;
	int		m = -12345678;
	char	*n = "abcdefghijklmnop";
	char	*o = "-a";
	char	*p = "-12";
	char	*q = "0";
	char	*r = "%%";
	char	*s = "-2147483648";
	char	*t = "0x12345678";
	char	*u = "-0";

result = printf("%4i, %4d, %4d, %4d, %4d, %4d, %4d      , %4d", i, j, k, l, m, c, e, d);
printf("result:%d\n", result);
result = ft_printf("%4i, %4d, %4d, %4d, %4d, %4d, %4d      , %4d", i, j, k, l, m, c, e, d);
printf("result:%d\n", result);

a = 4;
result = printf("%*.*i, %.4d, %.*d, %*d, %*d, %*d,       %*d, %*d", a, i, a, j, a, k, a, l, a, m, a, c, a, e, a, d);
printf("result:%d\n", result);
result = ft_printf("%*.*i, %.4d, %.*d, %*d, %*d, %*d,       %*d, %*d", a, i, a, j, a, k, a, l, a, m, a, c, a, e, a, d);
printf("result:%d\n", result);
*/
/*
result = ft_printf("%-2s, %.s, %-4s, %-2.4s, %-8.12s, %3s, %8s, %---2s, %.*s, %.0s, %.1s, %.2s, %.4s, %.8s", NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, -2, NULL, NULL, NULL, NULL, NULL, NULL);
printf("result:%d\n", result);
result = printf("%-2s, %.s, %-4s, %-2.4s, %-8.12s, %3s, %8s, %---2s, %.*s, %.0s, %.1s, %.2s, %.4s, %.8s", NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, -2, NULL, NULL, NULL, NULL, NULL, NULL);
printf("result:%d\n", result);
result = ft_printf("%c, %-c, %12c, %-3c, %-1c, %1c, %-2c, %-4c, %5c, %3c, %-*c, %-*c, %*c, %*c", 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, 0, 0, 0);
printf("result:%d\n", result);
result = printf("%c, %-c, %12c, %-3c, %-1c, %1c, %-2c, %-4c, %5c, %3c, %-*c, %-*c, %*c, %*c", 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, 0, 0, 0);
printf("result:%d\n", result);
*/
//	ft_printf("%10d", 10);
	result = ft_printf("%3.*d, %4-d, %1d, %13d",-12, 0, 23, -15, 2147988);
	printf("result:%d\n", result);
	result = printf("%3.*d, %4-.5d, %1d, %13d",-12, 0, 23, -15, 2147988);
	printf("result:%d\n", result);
}


