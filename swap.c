/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natalieyan <natalieyan@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 17:26:54 by natalieyan        #+#    #+#             */
/*   Updated: 2025/07/26 17:26:59 by natalieyan       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack **a)
{
	t_stack	*tmp;

	if (!a || !(*a) || stack_len(*a) < 2)
		return ;
	tmp = (*a);
	(*a) = (*a)->next;
	tmp->next = (*a)->next;
	(*a)->next = tmp;
}

void	sa(t_stack **a)
{
	write(1, "sa\n", 3);
	swap(a);
}

void	sb(t_stack **b)
{
	write(1, "sb\n", 3);
	swap(b);
}

void	ss(t_stack **a, t_stack **b)
{
	write(1, "ss\n", 3);
	swap(a);
	swap(b);
}
