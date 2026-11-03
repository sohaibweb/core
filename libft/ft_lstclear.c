/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabu-msa <sabu-msa@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/13 12:02:25 by sabu-msa          #+#    #+#             */
/*   Updated: 2026/09/20 10:37:15 by sabu-msa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*far;

	while (*lst != NULL)
	{
		far = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = far;
	}
}
