/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabu-msa <sabu-msa@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/17 10:15:59 by sabu-msa          #+#    #+#             */
/*   Updated: 2026/10/17 10:16:01 by sabu-msa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H

#include <stdlib.h>
#include <unistd.h>

typedef struct ft_push_swap
{
    int *data;
    struct ft_push_swap *next;
} t_list;

unsigned int    ft_lstsize(t_list *lst);
void                sa(t_list **stack_a);
void                sb(t_list **stack_b);
void                ss(t_list **stack_a, t_list **stack_b);
void                ra(t_list **stack_a);
void                rb(t_list **stack_b);
void                rr(t_list **stack_a, t_list **stack_b);
void                ft_lstadd_back(t_list **lst, t_list *new);
void                ft_lstdelone(t_list *lst);
void                ft_lstadd_front(t_list **lst, t_list *new);
void                ft_reverse_rotate(t_list **stack);
void                ft_rotate(t_list **stack);
void	            sort_three(t_list **stack_a);

t_list              *ft_lstnew(int *data);
t_list              *ft_lstlast(t_list *lst);

int                     ft_strlen(char *arr);
int                     check_input(char *arr);
int                     check_overflow(char *arr);
int                     write_error();
int                     ft_atoi(const char *nptr);

#endif