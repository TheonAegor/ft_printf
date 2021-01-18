#include "../includes/ft_printf.h"

int		init_delete(s_modif *flag, int i)
{
	if (i == 1)
	{
		flag->flag = 0;
		flag->width = 0;
		flag->precision = 0;
		flag->type = 0;
		flag->result = 0;
		flag->variable = 0;
	}
	else
	{
		flag->flag = 0;
		flag->width = 0;
		flag->precision = 0;
		flag->variable = 0;
		if (flag->type != '%')
			free(flag->variable);
		flag->type = 0;
	}
}
int		ft_print_precision(s_modif flag, int *res, int *tmp)
{
	int i;
	int len;
	i = 0;
	len = ft_strlen(flag.variable);
	if (flag.type == 's')
	{
		if (flag.precision >= len)
		{
			while(flag.variable[i])
				*tmp += ft_putchar(flag.variable[i++]);			
		}
		else if (flag.precision < len && flag.precision > 0)
		{
			while(flag.precision-- > 0)
				*tmp += ft_putchar(flag.variable[i++]);			
		}
		else
			*tmp += ft_putstr(flag.variable);
	}
	else
	{
	//	printf("\nhere\n");
		while(flag.precision - len++ > 0)
			*tmp += ft_putchar('0');
	//	printf("\nfv=%s|\n", flag.variable);
	//	printf("%d\n",
		if (flag.variable == NULL && (flag.precision == 0))
			return (*tmp);
		ft_putstr(flag.variable);
	}
	return (*tmp);
}

int		ft_write(s_modif *flag, char *line, int *i)
{
	while (line[*i] != '%' && line[*i])
	{
		ft_putchar(line[*i]);
		flag->result++;
		++*i;
	}
	if (line[*i] == '\0')
		return (0);
	return (1);
}	

int		ft_print_with_flags(s_modif *flag, int *res, char *line)
{
	int tmp;
	int len;

	tmp = 0;
	len = ft_strlen(flag->variable);
//	printf("\nlen=%d\n", len);
	if (flag->type == '%')
	{
		flag->result += ft_putchar('%');
		return (0);	
	}
	if (flag->width > len && flag->precision == 0)
	{
		if (flag->flag == 1)
		{
			ft_putstr(flag->variable);
			while(flag->width-- - len > 0)
				tmp += ft_putchar(' ');	
		}
		else if (flag->flag == 2 && flag->precision <= 0)
		{
			while(flag->width-- - len > 0)
				tmp += ft_putchar('0');			
			ft_putstr(flag->variable);
		}
		else
		{
			while(flag->width-- - len > 0)
				tmp += ft_putchar(' ');	
			ft_putstr(flag->variable);
		}
	}
	else
	{
		ft_print_precision(*flag, res, &tmp);
	}
	flag->result = flag->result + tmp;
//	printf("\nhere\n");
//	printf("\nfv=%s|\n", flag->variable);
	init_delete(flag, 0);
	return (tmp);
}

int ft_printf(const char *format, ...)
{
	char		*line;	
	s_modif		flag;
	va_list		args;
	int			i;

	i = 0;
	init_delete(&flag, 1);
	va_start(args, format);
	line = ft_strdup(format);
//	printf("\nline[i]=%d\n", line[i]);
	while (ft_write(&flag, line, &i) == 1)
	{
		ft_parser(line, args, &i, &flag);
		if (ft_processor(&flag, args, &i) < 0)
			return (-1);
//		printf("\nline[i]=%d\n", line[i]);
		ft_print_with_flags(&flag, &i, line);
	}
	va_end(args);
	return (flag.result);
}
