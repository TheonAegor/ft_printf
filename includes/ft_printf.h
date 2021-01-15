#ifndef FT_PRINTF_H 
# define FT_PRINTF_H

#include "libft.h"
#include "ft_parser.h"

int		ft_copysrc(char *dst, char *src);
int		ft_processor(s_modif *flag, va_list args);
void	ft_putnbr_u(unsigned x, int fd);
#endif
