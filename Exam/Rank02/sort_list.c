#include "list.h"

t_list *sort_list(t_list *lst, int (*cmp)(int, int))
{
    t_list  *node;
    int     temp;
    int     tru;

    if (!lst || !lst->next)
        return lst;

    while(1)
    {
        tru = 0;
        node = lst;
        while (node->next)
        {
            if (!cmp(node->data, node->next->data))
            {
                temp = node->data;
                node->data = node->next->data;
                node->next->data = temp;
                tru = 1;
            }
            node = node->next;
        }
        if (!tru)
            break;
    }
    return lst;
}

int cmp(int x, int y)
{
    if (x <= y)
        return 1;
    return 0;
}
