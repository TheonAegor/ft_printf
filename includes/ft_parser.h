#ifndef FT_PARSER_H  
# define FT_PARSER_H 

# include "libft.h" 

typedef struct		t_modif
{
	char	*type; //d,i,u,c,s,p,x,X
	int		precision; //.*(digit)
	int		width; //digit
	int		flag; //-,0
	
}					s_modif;

s_modif		ft_parser(char *format);
#endif
