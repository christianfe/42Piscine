#include "ft_list.h"

t_list	*ft_create_elem(void *data)
{
	t_list *list;

	list = malloc (sizeof(t_list));
	list->data = data;
	list->next = 0;
	return (list);
}


t_list	*ft_list_push_strs(int size, char **strs)
{
	int		i;
	t_list	*temp;
	t_list	*first;

	i = 0;
	first = 0;
	while (i < size)
	{
		temp = first;
		first = ft_create_elem(*strs[i]);
		first->next = temp;
		i++;
	}
	return (first);
}
