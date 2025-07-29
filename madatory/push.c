/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natalieyan <natalieyan@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 17:29:07 by natalieyan        #+#    #+#             */
/*   Updated: 2025/07/29 21:36:45 by natalieyan       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack **a, t_stack **b)
{
	t_stack	*tmp;

	if (!b || !(*b))
		return ;
	tmp = *b;
	(*b) = (*b)->next;
	if (!(*a))
		tmp->next = 0;
	else
		tmp->next = (*a);
	(*a) = tmp;
}

void	pa(t_stack **a, t_stack **b)
{
	write(1, "pa\n", 3);
	push(a, b);
}

void	pb(t_stack **a, t_stack **b)
{
	write(1, "pb\n", 3);
	push(b, a);
}
