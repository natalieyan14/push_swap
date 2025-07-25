/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natalieyan <natalieyan@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 13:15:54 by natalieyan        #+#    #+#             */
/*   Updated: 2025/07/24 22:22:07 by natalieyan       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	stack_size(t_stack **stack)
{
	int		count;
	t_stack	*curr;

	if (!stack)
		return (0);
	count = 0;
	curr = *stack;
	while (curr)
	{
		count++;
		curr = curr->next;
	}
	return (count);
}

void	free_stack(t_stack **stack)
{
	t_stack	*curr;

	if (!stack)
		return ;
	while (*stack)
	{
		curr = (*stack)->next;
		(*stack)->val = 0;
		free(*stack);
		(*stack) = curr;
	}
}

t_stack	*add_number_to_stack(int val)
{
	t_stack	*new_node;

	new_node = (t_stack *)malloc(sizeof(t_stack));
	if (!new_node)
		return (NULL);
	new_node->val = val;
	new_node->next = NULL;
	return (new_node);
}

void	add_tail_to_stack(t_stack **stack_head, t_stack *new_node)
{
	if (!stack_head)
		return ;
	if (!*stack_head)
		*stack_head = new_node;
	else
		(find_tail(*stack_head))->next = new_node;
}
