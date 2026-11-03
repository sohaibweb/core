int	is_sorted(t_list *stack_a)
{
	while (stack_a && stack_a->next)
	{
		if (stack_a->data > stack_a->next->data)
			return (1);
		stack_a = stack_a->next;
	}
	return (0);
}

