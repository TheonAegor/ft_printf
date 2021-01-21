#include "../includes/ft_printf.h"

int		init_delete(s_modif *flag, int i)
{
	if (i == 1)
	{
		flag->flag = 0;
		flag->width = 0;
		flag->precision = -1;
		flag->type = 0;
		flag->result = 0;
		flag->variable = 0;
	}
	else
	{
		flag->flag = 0;
		flag->width = 0;
		flag->precision = 0;
		flag->variable = NULL;
		free(flag->variable);
		flag->type = 0;
	}
	return (1);
}

int		ft_write(s_modif *flag, char *line, int *i)	
{
	while(line[*i] != '%' && line[*i])
	{
		ft_putchar(line[*i]);
		flag->result++;
		++*i;
	}
	if (line[*i] == '\0')
		return (0);
	return (1);
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
	while (ft_write(&flag, line, &i) == 1)
	{
		ft_parser(line, args, &i, &flag);
		if (ft_processor(&flag, args, &i) < 0)
		{
			init_delete(&flag, 0);
			return (-1);
		}
//		printf("\nline[i]=%c\n", line[i]);
	}
	init_delete(&flag, 0);
	va_end(args);
	return (flag.result);
}
