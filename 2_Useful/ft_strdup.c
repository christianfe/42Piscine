#include <stdlib.h>

char	*ft_strdup(char *str)
{
	int		i;
	char	*dest;
	
	dest = (char *)malloc(ft_strlen(str) * sizeof(char) + 1);
	if (dest == NULL)
		return (NULL);
	while (str[i])
	{
		dest[i] = str[i];
		i++;
	}
	dest[i] = 0;
	return (dest);
}

