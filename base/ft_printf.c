#include "libft.h"

typedef struct	specificator_list
{
	char	*param;
	char	*flags;
	int		width;
	int		precision;
	int		length;
	char	*type;
	
}				spec;

//%[parameter][flags][width][.precision][length]type
int ft_printf(const char *format, ...)
{
	char		*p_n;
	char		*line;	
	char		*reminder;

	line = ft_strdup(format);
	if ((p_n = ft_strchr(line, '%')))
	{
		*p_n = '\0';
		reminder = ft_strdup(++p_n);
	}
	ft_putstr(line);
	
	return (1);
}

/*
Объект: то что нужно напечатать
Свойства:
-параметр
-флаг
-ширина
-точность
-длина
-тип
*/
int main(void)
{
	int i = 5234;
	ft_printf("hello world%d", 123);	
	printf("\nМодификатор ширины поля: %07d\n",i);
	printf("\nМодификатор ширины поля: %70d\n",i);
}
