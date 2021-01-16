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
			printf("flag.variable:%s\n", flag.variable);
			return(res);
		}	
		res += ft_putstr(line);
//		printf("\nres =%d\n", res);
		ft_processor(&flag, args, &res);
		start++;
		ft_copysrc(line, &p_n[start]);
		start = 0;
	}
	return (res);
}
