/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   butterfly.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natalieyan <natalieyan@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 17:34:07 by natalieyan        #+#    #+#             */
/*   Updated: 2025/07/29 21:36:45 by natalieyan       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_with_offset(t_stack **a, t_stack **b, t_sortdata *data)
{
	if ((*a)->index <= data->min)
	{
		pb(a, b);
		data->rb_count++;
		data->min++;
	}
	else if ((*a)->index <= data->min + data->offset)
	{
		pb(a, b);
		data->min++;
	}
	else
		ra(a);
}

void	sort_in_b(t_stack **a, t_stack **b)
{
	t_sortdata	data;

	data.min = 0;
	data.offset = my_log2(2 * stack_len(*a)) * my_log5(0.25 * stack_len(*a));
	data.rb_count = 0;
	while (*a)
		push_with_offset(a, b, &data);
	while (data.rb_count-- > 0)
		rb(b);
}

int	get_position(t_stack *a, int index)
{
	int	i;

	i = 0;
	while (a)
	{
		if (a->index == index)
			return (i);
		i++;
		a = a->next;
	}
	return (i);
}

void	sort_in_a(t_stack **a, t_stack **b)
{
	int	max;
	int	position;

	max = stack_len(*b) - 1;
	while (*b)
	{
		position = get_position(*b, max);
		if (position <= stack_len(*b) / 2)
		{
			while (position-- > 0)
				rb(b);
		}
		else
		{
			while (position++ < stack_len(*b) - 1)
				rrb(b);
			rrb(b);
		}
		pa(a, b);
		max--;
	}
}

void	butterfly_sort(t_stack **a, t_stack **b)
{
	sort_in_b(a, b);
	sort_in_a(a, b);
}
