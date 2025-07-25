/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natalieyan <natalieyan@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 13:27:26 by natalieyan        #+#    #+#             */
/*   Updated: 2025/07/24 22:22:02 by natalieyan       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	rotate_before_push(t_stack **a, int count_largest, int size)
{
	int	r_count;

	if (count_largest > size / 2)
		r_count = size - count_largest;
	else
		r_count = count_largest;
	exec_rotate_1(a, r_count, size, count_largest);
}

void	rotate_after_push(t_stack **a, int count_largest, int size)
{
	int	r_count;

	if (count_largest >= size / 2)
		r_count = size - count_largest;
	else
		r_count = count_largest + 1;
	exec_rotate_2(a, r_count, size, count_largest);
}

void	sort_stack_of_5(t_stack **a, t_stack **b)
{
	t_stack	*tmp;
	int		size;
	int		count_largest;

	while (stack_size(a) > 3)
		pb(a, b);
	sort_stack_of_3(a);
	while (*b)
	{
		size = stack_size(a);
		tmp = *a;
		while (tmp && tmp->val < (*b)->val)
			tmp = tmp->next;
		count_largest = stack_size(&tmp);
		rotate_before_push(a, count_largest, size);
		pa(a, b);
		rotate_after_push(a, count_largest, size);
	}
}
