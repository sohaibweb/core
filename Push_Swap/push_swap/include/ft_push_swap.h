/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabu-msa <sabu-msa@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/17 10:15:59 by sabu-msa          #+#    #+#             */
/*   Updated: 2026/10/27 12:27:06 by sabu-msa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	int				data;
	int				index;
	struct s_list	*next;
}	t_list;

typedef enum e_strategy
{
	SIMPLE,
	MEDIUM,
	COMPLEX,
	ADAPTIVE
}	t_strategy;

unsigned int	ft_lstsize(t_list *lst);
void			sa(t_list **stack_a);
void			sb(t_list **stack_b);
void			ss(t_list **stack_a, t_list **stack_b);
void			pa(t_list **stack_a, t_list **stack_b);
void			pb(t_list **stack_a, t_list **stack_b);
void			ra(t_list **stack_a);
void			rb(t_list **stack_b);
void			rr(t_list **stack_a, t_list **stack_b);
void			rra(t_list **stack_a);
void			rrb(t_list **stack_b);
void			rrr(t_list **stack_a, t_list **stack_b);
void			ft_lstadd_back(t_list **lst, t_list *new);
void			ft_lstadd_front(t_list **lst, t_list *new);
void			push_swap(t_list **stack_a, t_strategy strategy);
void			sort_small(t_list **stack_a);
void			free_split(char **split);
void			free_stack(t_list *stack);
void			sort_simple(t_list **stack_a, t_list **stack_b);
void			sort_big(t_list **stack_a, t_list **stack_b, int size);
void			push_to_b(t_list **stack_a, t_list **stack_b, int size);
void			push_to_a(t_list **stack_a, t_list **stack_b, int size);
void			radix_sort(t_list **stack_a, t_list **stack_b);

char			*ft_strchr(const char *s, int c);
char			**ft_split(char const *s, char c);
char			*ft_substr(char const *s, unsigned int start, size_t len);

int				check_duplicate(t_list *stack);
int				check_input(char *arr);
int				check_overflow(char *arr);
int				write_error(void);
int				ft_strlen(char *arr);
int				ft_atoi(const char *nptr);
int				has_space(char *str);
int				disorder(t_list *stack);
double			disorder_ratio(t_list *stack);
int				assign_indices(t_list *stack_a, int stack_size);

t_list			*ft_lstnew(int *data);
t_list			*ft_lstlast(t_list *lst);
t_strategy		get_strategy(int argc, char **argv, int *start, int *error);

#endif