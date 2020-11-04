int	*ft_map(int *tab, int length, int(*f)(int))
{
	int *ris;
	int i;

	i = 0;
	ris = malloc(sizeof(int) * length);
	if (!ris)
		return (0);
	while (i < length)
	{
		ris[i] = f(tab[i]);
		i++;
	}
	return (ris);
}