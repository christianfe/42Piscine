#include <stdio.h>

char	*ft_convert_base(char *nbr, char *base_from, char *base_to);

int main()
{
	printf("%s", ft_convert_base("-254", "0123456789", "AB"));
	return 0;
}