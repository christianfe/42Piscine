void	ft_reverse_str(char *str, int size)
{
	int i;
	char temp;
	
	i = 0;
	size--;
	while (i < size)
	{
		temp = str[i];
		str[i] = str[size];
		str[size] = temp;
		size--;
		i++;
	}
}
