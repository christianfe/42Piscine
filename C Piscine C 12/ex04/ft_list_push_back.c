#include "ft_list.h"

t_list	*ft_create_elem(void *data)
{
	t_list *list;

	list = malloc (sizeof(t_list));
	list->data = data;
	list->next = 0;
	return (list);
}

void	ft_list_push_back(t_list **begin_list, void *data)
{
	t_list *last;
	t_list *t;

	last = ft_create_elem(data);
	if (!*begin_list)
	{
		*begin_list = last;
		return ;
	}
	t = *begin_list;
	while(t->next)
		t = t->next;
	t->next = last;
}