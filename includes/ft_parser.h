#ifndef FT_PARSER_H  
# define FT_PARSER_H 

typedef struct		t_modif
{
	char	type; //d,i,u,c,s,p,x,X
	int		precision; //.*(digit)
	int		width; //digit
	int		flag; //-,0
	int		varg;
	int		result;
	char	*variable;
}					s_modif;

int			ft_parser(char *format, va_list args, int *i, s_modif *flag);
#endif
