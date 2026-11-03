#include "ft_push_swap.h"
#include <stdio.h>

int main()
{
    t_list  *node1;
    t_list  *node2;
    t_list  *node3;
    
    int n1 = 2;
    int n2 = 1;
    int n3 = 3;

    node1 = ft_lstnew(&n1);
    node2 = ft_lstnew(&n2);
    node3 = ft_lstnew(&n3);

   ft_lstadd_back(&node1, node2);
   ft_lstadd_back(&node1, node3);

   printf("%d\n", *node1->data);
   printf("%d\n", *node1->next->data);
   printf("%d\n", *node1->next->next->data);
   
   rb(&node1);

   printf("%d\n", *node1->data);
   printf("%d\n", *node1->next->data);
   printf("%d\n", *node1->next->next->data);
}