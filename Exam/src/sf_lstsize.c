/* ************************************************************************** */
/*                                                                            */
/*   sf_lstzise.c                                     ███████╗███████╗        */
/*   By: sohaib <sohaib@student.com>                  ██╔════╝██╔════╝        */
/*   Created: 2026/10/06 16:45:03 by sohaib           ███████╗█████╗          */
/*   Updated: 2026/10/06 16:45:03 by sohaib           ╚════██║██╔══╝          */
/*                                                    ███████║██║             */
/*                                                    ╚══════╝╚═╝             */
/* ************************************************************************** */
#include <stdlib.h>
#include <stdio.h>

typedef struct list
{
	void *content;
	struct list	*next;
} t_list;

unsigned int	sf_lstsize(t_list *lst)
{
	int	count;

	count = 0;
	if (!lst)
		return (0);
	while (lst != NULL)
	{
		count++;
		lst = lst->next;
	}
	return (count);
}

int	main()
{
	int n = 5;
	int x = 10;
	t_list *node;
	t_list *node1;

	node = malloc(sizeof(t_list));
	node1 = malloc(sizeof(t_list));
	if (!node)
		return (0);
	node->content = &n;
	node1->content = &x;
	node->next = node1;
	node1->next = NULL;

	int i = sf_lstsize(node);
	printf("%d\n", i);
	n = 5;
}