#	include "./includes/ft_printf.h"

	enum ints {max = 2147483647, min = -2147483648, z = 0, o = 1, simple = 234};
	enum chars {a = 97, A = 65, one = 49, question = 64, zer = 0}; 

int main(void)
{

	int result;
	int i = 0;
	char *str_0 = "";
	char *str_1 = "hello";
	char *strs[] = {str_0, str_1, NULL};
	char *p_str;
	enum chars arr_ch[] = {a, A, question, one, zer};
	enum chars iter;
	enum ints arr[5] = {o, z, simple, max, min};
	enum ints iterator;

/*
	printf("=============================TEST INT======================\n");	
	while (i < 5)
	{
		iterator = arr[i];
		result = ft_printf("%10d", iterator);
		printf("1)mine:%d\n", result);
		result = printf("%10d", iterator);
		printf("2)original:%d\n\n", result);
		i++;
	}
	printf("=============================TEST HEX======================\n");	
	i = 0;
	while (i < 5)
	{
		iterator = arr[i];
		result = ft_printf("%10x\t", iterator);
		printf("1)mine:%d\n", result);
		result = printf("%10x\t", iterator);
		printf("2)original:%d\n\n", result);
		i++;
	}

	printf("=============================TEST UNSIGNED======================\n");	
	i = 0;
	while (i < 5)
	{
		iterator = arr[i];
		result = ft_printf("%10u\t", iterator);
		printf("1)mine:%d\n", result);
		result = printf("%10u\t", iterator);
		printf("2)original:%d\n\n", result);
		i++;
	}
	printf("=============================TEST STRING======================\n");	
	i = 0;
	while (i < 2)
	{
		p_str = strs[i];
		result = ft_printf("%10s\t", p_str);
		printf("1)mine:%d\n", result);
		result = printf("%10s\t", p_str);
		printf("2)original:%d\n\n", result);
		i++;
	}
*/
	printf("=============================TEST CHAR======================\n");	
	i = 0;
	while (i < 5)
	{
		iter = arr_ch[i];
		result = ft_printf("%10c\t", iter);
		printf("1)mine:%d\n", result);
		result = printf("%10c\t", iter);
		printf("2)original:%d\n\n", result);
		i++;
	}
/*
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
	result = ft_printf("%%%d", 5);
	printf("1)mine:%d\n", result);
	result = printf("%%%d", 5);
	printf("2)original:%d\n\n", result);
	result = ft_printf("%-05%%d", 5);
	printf("1)mine:%d\n", result);
	result = printf("%%%d", 5);
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
		result = ft_printf("%d\t", iterator);
		printf("1)mine:%d\n", result);
		result = printf("%*.*d\t",2,3, iterator);
		printf("2)original:%d\n\n", result);
		i++;
	}
	printf("=============================TEST 0======================\n");	
	i = 0;
	while (i < 5)
	{
		iterator = arr[i];
		result = ft_printf("%.d", iterator);
		printf("(1)mine:%d\n", result);
		result = printf("%.d", iterator);
		printf("(2)original:%d\n\n", result);
		i++;
	}
*/

}

