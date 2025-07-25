/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_helpers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natalieyan <natalieyan@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 02:00:41 by natalieyan        #+#    #+#             */
/*   Updated: 2025/07/25 20:53:46 by natalieyan       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	sort_stack_of_2(t_stack **stack)
{
	if ((*stack)->val > (*stack)->next->val)
		swap(stack);
}

void	sort_stack_of_3(t_stack **stack)
{
	int	a;
	int	b;
	int	c;

	a = (*stack)->val;
	b = (*stack)->next->val;
	c = (*stack)->next->next->val;
	if (a > b && b < c && a < c)
		swap(stack);
	else if (a > b && b > c)
	{
		swap(stack);
		reverse_rotate(stack);
	}
	else if (a > b && b < c && a > c)
		rotate(stack);
	else if (a < b && b > c && a < c)
	{
		swap(stack);
		rotate(stack);
	}
	else if (a < b && b > c && a > c)
		reverse_rotate(stack);
}
