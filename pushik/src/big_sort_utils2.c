/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort_utils2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natalieyan <natalieyan@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 13:16:55 by natalieyan        #+#    #+#             */
/*   Updated: 2025/07/24 22:18:56 by natalieyan       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	exec_initial_moves(t_stack **a, t_stack **b)
{
	int	size_a;
	int	sum;
	int	med;

	size_a = 0;
	sum = 0;
	med = 0;
	while (stack_size(a) > 3)
	{
		size_a = stack_size(a);
		sum = sum_val(a);
		med = sum / size_a;
		if ((*a)->val < med)
			pb(a, b);
		else
			ra(a);
	}
}

void	set_cost_table(t_stack **a, t_stack **b, t_cost_tab **table)
{
	int		bf;
	int		val;
	int		val_cost;
	t_stack	*tmp_b;

	tmp_b = *b;
	while (tmp_b)
	{
		val = tmp_b->val;
		bf = find_bf(a, val);
		val_cost = calc_cost(val, bf, a, b);
		if (!*table)
			(*table) = add_cost(val, bf, val_cost);
		else
			add_tail_to_cost_table(table, add_cost(val, bf, val_cost));
		tmp_b = tmp_b->next;
	}
}

int	get_best_cost_posix(t_cost_tab **table)
{
	t_cost_tab	*curr;
	int			best_cost_posix;
	int			best_cost_val;
	int			i;

	curr = *table;
	best_cost_val = curr->cost;
	i = 0;
	best_cost_posix = 0;
	while (curr)
	{
		if (curr->cost < best_cost_val)
		{
			best_cost_posix = i;
			best_cost_val = curr->cost;
			i++;
		}
		else
			i++;
		curr = curr->next;
	}
	return (best_cost_posix);
}
