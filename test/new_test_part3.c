#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libft.h"

    /* ft_lstnew */
int main()
{
    t_list *node;

    node = ft_lstnew(strdup("hello"));
    printf("%s\n", (char *)node->content);
    printf("%p\n", (void *)node->next);
    free(node->content);
    free(node);

    return 0;
}

    /* ft_lstadd_front */
int main()
{
    t_list *lst;
    t_list *a;
    t_list *b;

    lst = ft_lstnew(strdup("b"));
    a = ft_lstnew(strdup("a"));
    ft_lstadd_front(&lst, a);
    printf("%s\n", (char *)lst->content);
    printf("%s\n", (char *)lst->next->content);

    b = lst;
    while (b)
    {
        free(b->content);
        b = b->next;
    }
    free(lst->next);
    free(lst);

    return 0;
}

    /* ft_lstsize */
int main()
{
    t_list *lst;
    t_list *second;
    t_list *third;

    lst = ft_lstnew(strdup("a"));
    second = ft_lstnew(strdup("b"));
    third = ft_lstnew(strdup("c"));
    lst->next = second;
    second->next = third;

    printf("%d\n", ft_lstsize(lst));
    printf("%d\n", ft_lstsize(NULL));

    free(lst->content);
    free(second->content);
    free(third->content);
    free(lst);
    free(second);
    free(third);

    return 0;
}

    /* ft_lstlast */
int main()
{
    t_list *lst;
    t_list *second;
    t_list *third;
    t_list *last;

    lst = ft_lstnew(strdup("a"));
    second = ft_lstnew(strdup("b"));
    third = ft_lstnew(strdup("c"));
    lst->next = second;
    second->next = third;

    last = ft_lstlast(lst);
    printf("%s\n", (char *)last->content);

    free(lst->content);
    free(second->content);
    free(third->content);
    free(lst);
    free(second);
    free(third);

    return 0;
}

    /* ft_lstadd_back */
int main()
{
    t_list *lst;
    t_list *newnode;
    t_list *tmp;

    lst = ft_lstnew(strdup("a"));
    newnode = ft_lstnew(strdup("b"));
    ft_lstadd_back(&lst, newnode);

    tmp = lst;
    while (tmp)
    {
        printf("%s\n", (char *)tmp->content);
        tmp = tmp->next;
    }

    tmp = lst;
    while (tmp)
    {
        free(tmp->content);
        tmp = tmp->next;
    }
    free(lst->next);
    free(lst);

    return 0;
}

    /* ft_lstdelone */
void del_content(void *content)
{
    free(content);
}

int main()
{
    t_list *node;

    node = ft_lstnew(strdup("hello"));
    ft_lstdelone(node, del_content);

    return 0;
}

    /* ft_lstclear */
void del_content2(void *content)
{
    free(content);
}

int main()
{
    t_list *lst;
    t_list *second;
    t_list *third;

    lst = ft_lstnew(strdup("a"));
    second = ft_lstnew(strdup("b"));
    third = ft_lstnew(strdup("c"));
    lst->next = second;
    second->next = third;

    ft_lstclear(&lst, del_content2);
    printf("%p\n", (void *)lst);

    return 0;
}

    /* ft_lstiter */
void print_content(void *content)
{
    printf("%s\n", (char *)content);
}

int main()
{
    t_list *lst;
    t_list *second;
    t_list *third;

    lst = ft_lstnew(strdup("a"));
    second = ft_lstnew(strdup("b"));
    third = ft_lstnew(strdup("c"));
    lst->next = second;
    second->next = third;

    ft_lstiter(lst, print_content);

    free(lst->content);
    free(second->content);
    free(third->content);
    free(lst);
    free(second);
    free(third);

    return 0;
}
       /*ft_lstmap*/
int main()
{
    int nb1 = 5;
    int nb2 = 10;
    int nb3 = 15;
    t_list  *list = NULL;
    t_list  *new_map = NULL;

    ft_lstadd_back(&list, ft_lstnew(&nb1));
    ft_lstadd_back(&list, ft_lstnew(&nb2));
    ft_lstadd_back(&list, ft_lstnew(&nb3));

    new_map = ft_lstmap(list, f, del);

    printf("%d\n", *(int *)new_map->content);
    printf("%d\n", *(int *)new_map->next->content);
    printf("%d\n", *(int *)new_map->next->next->content);

    ft_lstclear(&new_map, del);

    t_list  *p;

    while (list)
    {
        p = list->next;
        free(list);
        list = p;
    }
        return (0);
}