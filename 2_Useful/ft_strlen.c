int	ft_strlen(char *str)
{
	char	*charptr;
	int		i;

	i = 0;
	charptr = str;
	while (*charptr != 0)
	{
		i++;
		charptr++;
	}
	return (i);
}
