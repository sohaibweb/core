/* ************************************************************************** */
/*                                                                            */
/*   sf_lstiter.c                                     ███████╗███████╗        */
/*   By: sohaib <sohaib@student.com>                  ██╔════╝██╔════╝        */
/*   Created: 2026/10/06 17:31:51 by sohaib           ███████╗█████╗          */
/*   Updated: 2026/10/06 17:31:51 by sohaib           ╚════██║██╔══╝          */
/*                                                    ███████║██║             */
/*                                                    ╚══════╝╚═╝             */
/* ************************************************************************** */

typedef struct list
{
	void *content;
	struct list	*next;
} t_list;

void    sf_lstiter(t_list *lst, void (*f)(void *))
{
	if (!lst)
		return NULL;
    	while(lst)
    	{
        	f(lst->content);
        	lest = lst->next;
    	}
}
