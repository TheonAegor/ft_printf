#ifndef FT_PRINTF_H 
# define FT_PRINTF_H

#include "libft.h"
#include "ft_parser.h"

int 	ft_print_prec_less_neg(s_modif *flag);
int     ft_printf(const char *format, ...);
int		ft_copysrc(char *dst, char *src);
int		ft_processor(s_modif *flag, va_list args, int *res);
int		ft_putnbr_u(unsigned x);
int		ft_find_tens(unsigned long x);
int		ft_proc_hex(unsigned long x, s_modif *flag);
int		ft_find_sixteens(unsigned long x);
int		ft_proc_p(unsigned long x, s_modif *flag);
int		ft_proc_s(char *str, s_modif *flag);
int		ft_proc_c(int c, s_modif *flag);
int		ft_proc_u(unsigned long int x, s_modif *flag);
int		ft_proc_d(int x, s_modif *flag);
int		ft_proc_percent(s_modif *flag);
int 	ft_printspace(s_modif *flag);
int 	ft_printzero(s_modif *flag);
int 	print_precision(s_modif *flag);
int 	ft_calc_flags(s_modif *flag);
int 	print_flags(s_modif *flag);
int 	ft_check_minus(s_modif *flag);
char 	*ft_itoa_unsigned(unsigned long int x);
char 	*ft_itoa_base(unsigned long long int x);

#endif
