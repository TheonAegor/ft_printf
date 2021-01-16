#include "../includes/ft_printf.h"

int		ft_print_precision(s_modif flag, int *res, int *tmp)
{
	int i;
//	printf("prec=%d\n", flag.precision);
	i = 0;
	if (flag.precision > *res && flag.type == 's')
	{
		*tmp -= *res;
		while(flag.variable[i])
			*tmp += ft_putchar(flag.variable[i++]);			
	}
	else if (flag.precision < *res && flag.type == 's')
	{
		*tmp -= *res;
		while(flag.precision-- > 0)
			*tmp += ft_putchar(flag.variable[i++]);			
	}
	if (flag.precision > *res && flag.type != 's')
	{
		while(flag.precision-- - *res > 0)
			*tmp += ft_putchar('0');
		ft_putstr(flag.variable);
	}
	*res += *tmp;
	return (1);
}

int		ft_print_with_flags(s_modif flag, int *res, char *line)
{
	int tmp;
//	printf("res=%d\n", res);
//	printf("flag.width=%d\n", flag.width);
//	printf("flag.flag=%d\n", flag.flag);

	tmp = 0;
	tmp = ft_putstr(line);
	
	if (flag.width > 0 && *res < flag.width && flag.flag == 1)
	{
		ft_putstr(flag.variable);
		while(flag.width-- - *res > 0)
			tmp += ft_putchar(' ');			
	}
	else if (flag.width > 0 && *res < flag.width && flag.flag == 2)
	{
		while(flag.width-- - *res > 0)
			tmp += ft_putchar('0');			
		ft_putstr(flag.variable);
	}
	if (flag.flag == 0 && flag.type != 's' && flag.precision == 0)
	{
		while(flag.width-- - *res > 0)
			tmp += ft_putchar(' ');			
		ft_putstr(flag.variable);
	}
//	printf("tmp=%d\n", tmp);
	ft_print_precision(flag, res, &tmp);
	return (1);
}

//%[parameter][flags][width][.precision][length]type
int ft_printf(const char *format, ...)
{
	char		*p_n;
	char		*line;	
	s_modif		flag;
	va_list		args;
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
			ft_print_with_flags(flag, &res, line);
			res += ft_putstr(line);
			return(res);
		}	
		ft_processor(&flag, args, &res);
//		printf("res=%d\n", res);
		ft_print_with_flags(flag, &res, line);
		start++;
		ft_copysrc(line, &p_n[start]);
		start = 0;
	}
	return (res);
}
