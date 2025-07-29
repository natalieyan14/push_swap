/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natalieyan <natalieyan@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 17:27:27 by natalieyan        #+#    #+#             */
/*   Updated: 2025/07/29 21:36:45 by natalieyan       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_stack **a)
{
	t_stack	*first;
	t_stack	*tmp;

	if (!a || !(*a) || stack_len(*a) < 2)
		return ;
	first = (*a);
	(*a) = (*a)->next;
	tmp = (*a);
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = first;
	first->next = 0;
}

void	ra(t_stack **a)
{
	write(1, "ra\n", 3);
	rotate(a);
}

void	rb(t_stack **b)
{
	write(1, "rb\n", 3);
	rotate(b);
}

void	rr(t_stack **a, t_stack **b)
{
	write(1, "rr\n", 3);
	rotate(a);
	rotate(b);
}
