/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natalieyan <natalieyan@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 13:17:53 by natalieyan        #+#    #+#             */
/*   Updated: 2025/07/24 22:14:14 by natalieyan       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	rotate(t_stack **stack)
{
	t_stack	*last;
	t_stack	*tmp;

	if (!*stack || !(*stack)->next)
		return ;
	last = *stack;
	tmp = last->next;
	while (last->next)
		last = last->next;
	last->next = *stack;
	*stack = tmp;
	last->next->next = NULL;
}

void	ra(t_stack **a)
{
	rotate(a);
	write(1, "ra\n", 3);
}

void	rb(t_stack **b)
{
	rotate(b);
	write(1, "rb\n", 3);
}

void	rr(t_stack **a, t_stack **b)
{
	ra(a);
	rb(b);
}
