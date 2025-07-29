/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexes.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natalieyan <natalieyan@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 17:32:56 by natalieyan        #+#    #+#             */
/*   Updated: 2025/07/29 21:36:45 by natalieyan       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	min(t_stack *a)
{
	int	min;

	min = INT_MAX;
	while (a)
	{
		if (a->data < min)
			min = a->data;
		a = a->next;
	}
	return (min);
}

int	stack_len(t_stack *a)
{
	int	i;

	i = 0;
	while (a)
	{
		i++;
		a = a->next;
	}
	return (i);
}

void	set_index(int min, t_stack *a, int index)
{
	while (a)
	{
		if (a->data == min)
		{
			a->index = index;
			break ;
		}
		a = a->next;
	}
}

int	next_min(int prev_min, t_stack *a)
{
	int	min;

	min = INT_MAX;
	while (a)
	{
		if (a->data < min && a->data > prev_min)
			min = a->data;
		a = a->next;
	}
	return (min);
}

void	setting_indexes(t_stack **a)
{
	int	prev_min;
	int	index;

	prev_min = min(*a);
	index = 0;
	set_index(prev_min, *a, index);
	index++;
	while (index < stack_len(*a))
	{
		prev_min = next_min(prev_min, *a);
		set_index(prev_min, *a, index);
		index++;
	}
}
