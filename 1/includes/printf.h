/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heula <heula@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 14:15:12 by heula             #+#    #+#             */
/*   Updated: 2021/01/13 20:18:35 by heula            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include "../libft/libft.h"

typedef struct	s_mode
{
	va_list		s;
	const char	*str;
	char		flag;
	int			width;
	int			accuracy;
	char		type;
	int			result;
}				t_mode;

int				ft_printf(const char *string, ...);
const char		*ft_write(t_mode *format);
int				parserstart(t_mode *format);
void			printzero(char *str, int count);
void			printspace(char *str, int count);
int				printifnull (t_mode *format);
int				print_c(t_mode *format);
int				print_s(t_mode *format);
int				print_percent(t_mode *format);
int				print_d_i(t_mode *format);
int				print_hex(t_mode *format);
int				print_u(t_mode *format);
int				print_p(t_mode *format);
void			flags_width_num(t_mode *format, char *output);
void			accuracy_num(t_mode *format, char *output);
void			reverse_line(char **output);
char			*itoa_base(unsigned long long int num);

#endif
