#include <stdio.h>

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)

int main ()
{
	printf("%s", ft_convert_base("01234", "0123456789", "01"));
	return 0;
}