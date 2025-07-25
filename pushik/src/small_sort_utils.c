/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natalieyan <natalieyan@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 13:12:54 by natalieyan        #+#    #+#             */
/*   Updated: 2025/07/24 22:21:58 by natalieyan       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	exec_rotate_2(t_stack **a, int rotate_count, int size,
		int count_largest)
{
	if (!*a)
		return ;
	while (rotate_count)
	{
		if (size - count_largest <= size / 2)
			rra(a);
		else
			ra(a);
		rotate_count--;
	}
}

void	exec_rotate_1(t_stack **a, int rotate_count, int size,
		int count_largest)
{
	if (!*a)
		return ;
	while (rotate_count)
	{
		if (size - count_largest <= size / 2)
			ra(a);
		else
			rra(a);
		rotate_count--;
	}
}
