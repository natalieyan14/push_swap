/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natalieyan <natalieyan@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 17:27:36 by natalieyan        #+#    #+#             */
/*   Updated: 2025/07/26 17:27:39 by natalieyan       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rev_rotate(t_stack **a)
{
	t_stack	*tmp;
	t_stack	*last;

	if (*a == NULL || a == NULL)
		return ;
	tmp = (*a);
	last = 0;
	while (tmp->next)
	{
		if (!(tmp->next->next))
		{
			last = tmp->next;
			tmp->next = 0;
			break ;
		}
		tmp = tmp->next;
	}
	if (last)
	{
		last->next = (*a);
		(*a) = last;
	}
}

void	rra(t_stack **a)
{
	write(1, "rra\n", 4);
	rev_rotate(a);
}

void	rrb(t_stack **b)
{
	write(1, "rrb\n", 4);
	rev_rotate(b);
}

void	rrr(t_stack **a, t_stack **b)
{
	write(1, "rrr\n", 3);
	rev_rotate(a);
	rev_rotate(b);
}
