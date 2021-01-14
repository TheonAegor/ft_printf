#include "../includes/ft_parser.h"
#include "../includes/libft.h"

int main(void)
{
	s_modif flag;

	flag = ft_parser("-555.10d");
	printf("%d\n", flag.flag);
	printf("%d\n", flag.width);
	printf("%d\n", flag.width);
	printf("%d\n", flag.precision);

}
