int ft_count_if(char **tab, int length, int(*f)(char*))
{
	int i;
	int ris;

	ris = 0;
	i = 0;
	while (i < length)
	{
		if (f(tab[i]))
			ris++;
		i++;
	}
	return (ris);
}