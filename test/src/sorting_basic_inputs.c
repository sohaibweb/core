static void	sort_two(t_list **stack_a)
{
	if ((*stack_a)->data > (*stack_a)->next->data)
		sa(stack_a);
}

void	sort_three(t_list **stack_a)
{
	int	x;
	int	y;
	int	z;

	x = (*stack_a)->data;
	y = (*stack_a)->next->data;
	z = (*stack_a)->next->next->data;
	if (x > y && y < z && x < z)
		sa(stack_a);
	else if (x > y && y > z)
	{
		sa(stack_a);
		rra(stack_a);
	}
	else if (x > y && y < z && x > z)
		ra(stack_a);
	else if (x < y && y > z && x < z)
	{
		sa(stack_a);
		ra(stack_a);
	}
	else if (x < y && y > z && x > z)
		rra(stack_a);
}