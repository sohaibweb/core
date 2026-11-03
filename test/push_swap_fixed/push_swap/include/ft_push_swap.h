/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabu-msa <sabu-msa@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/31 15:00:00 by sabu-msa          #+#    #+#             */
/*   Updated: 2026/10/31 15:00:00 by sabu-msa         ###   ########.fr       */
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

typedef enum e_mode
{
	SIMPLE,
	MEDIUM,
	COMPLEX,
	ADAPTIVE
}	t_mode;

typedef enum e_op
{
	OP_SA,
	OP_SB,
	OP_SS,
	OP_PA,
	OP_PB,
	OP_RA,
	OP_RB,
	OP_RR,
	OP_RRA,
	OP_RRB,
	OP_RRR,
	OP_COUNT
}	t_op;

typedef struct s_ctx
{
	t_list		*a;
	t_list		*b;
	t_mode		mode;
	t_mode		used;
	int			bench;
	long long	mistakes;
	long long	pairs;
	int			ops[OP_COUNT];
}	t_ctx;

void			sa(t_ctx *c);
void			sb(t_ctx *c);
void			ss(t_ctx *c);
void			pa(t_ctx *c);
void			pb(t_ctx *c);
void			ra(t_ctx *c);
void			rb(t_ctx *c);
void			rr(t_ctx *c);
void			rra(t_ctx *c);
void			rrb(t_ctx *c);
void			rrr(t_ctx *c);

unsigned int	ft_lstsize(t_list *lst);
void			ft_lstadd_back(t_list **lst, t_list *new);
void			ft_lstadd_front(t_list **lst, t_list *new);
t_list			*ft_lstnew(int *data);
t_list			*ft_lstlast(t_list *lst);

char			*ft_strchr(const char *s, int c);
char			**ft_split(char const *s, char c);
char			*ft_substr(char const *s, unsigned int start, size_t len);
int				ft_strlen(char *arr);
int				ft_strcmp(const char *s1, const char *s2);
int				ft_atoi(const char *nptr);
void			ft_putstr_fd(char *s, int fd);
void			ft_putnbr_fd(long long n, int fd);
void			put_pct(long long mistakes, long long pairs);

int				check_duplicate(t_list *stack);
int				check_input(char *arr);
int				check_overflow(char *arr);
int				parse_args(int argc, char **argv, t_ctx *c);
int				write_error(void);

void			free_split(char **split);
void			free_stack(t_list *stack);
int				has_two(t_list *stack);
void			init_ctx(t_ctx *c);
int				total_ops(t_ctx *c);
void			print_bench(t_ctx *c);

long long		disorder(t_list *stack);
int				push_swap(t_ctx *c);
int				assign_indices(t_list *stack, int size);
void			sort_small(t_ctx *c);
void			sort_simple(t_ctx *c);
void			sort_big(t_ctx *c, int size);
void			push_to_b(t_ctx *c, int size);
void			push_to_a(t_ctx *c, int size);
void			radix_sort(t_ctx *c);

#endif
