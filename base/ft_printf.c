#include "../includes/ft_printf.h"

//%[parameter][flags][width][.precision][length]type
int ft_printf(const char *format, ...)
{
	char		*p_n;
	char		*line;	
	s_modif		flag;
	va_list		args;
	int			num;
	int			start;
	int			res;

	start = 0;
	va_start(args, format);
//	num = va_arg(args, int);	
//	printf("%d\n", num);
	line = ft_strdup(format);
	res = 0;
	while (*line)
	{
		if ((p_n = ft_strchr(line, '%')))
		{
			*p_n = '\0';
			flag = ft_parser(++p_n, args, &start);
		}
		else
		{
			res += ft_putstr(line);
			return(res);
		}	
		res += ft_putstr(line);
		ft_processor(&flag, args);
		start++;
		ft_copysrc(line, &p_n[start]);
		start = 0;
	}
/*
	printf("flag.flag: %d\n", flag.flag);
    printf("flag.width: %d\n", flag.width);
    printf("flag.precision: %d\n", flag.precision);
    printf("flag.type: %c\n", flag.type);
*/
	
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
