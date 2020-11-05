#include "ft_list.h"
# include <stdlib.h>

void ft_list_clear(t_list *begin_list, void (*free_fct)(void *))
{
	t_list *val;

	while(begin_list->next)
	{
		val = begin_list;
		free_fct(val->data);
		begin_list = begin_list->next;
		free(val);
	}
}
