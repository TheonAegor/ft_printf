#include "../includes/ft_printf.h"

int		ft_proc_p(unsigned long int x, int *res, s_modif *flag)
{
    long long int   category;
    unsigned long int           tmp;

    category = ft_find_sixteens(x) + 2;
    flag->variable = ft_calloc(sizeof(char), category + 2);
    flag->variable[category--] = '\0';
	*res = *res + 2;
    while (category > 1 )
    {
    //    printf("%ld\n", x);
        tmp = x % 16;
        if (tmp < 10)                              
            flag->variable[category--] = tmp + 48;
        if (tmp >= 10 && tmp <= 15)                                            flag->variable[category--] = ((tmp + 1) % 10) | 48 ^ 80;                                          
        ++*res;    
        x = x / 16;
    } 
    printf("\ncategory:%lld\n", category);
	flag->variable[category--] = 'x';
	flag->variable[category] = '0';
    return (1);
}
