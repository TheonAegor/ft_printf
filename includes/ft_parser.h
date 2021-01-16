#ifndef FT_PARSER_H  
# define FT_PARSER_H 

typedef struct		t_modif
{
	char	type; //d,i,u,c,s,p,x,X
	int		precision; //.*(digit)
	int		width; //digit
	int		flag; //-,0
	int		varg;
	char	*variable;
}					s_modif;

s_modif		ft_parser(char *format, va_list args, int *i);
int			ft_printf(const char *format, ...);
#endif
