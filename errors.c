/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natalieyan <natalieyan@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 17:33:41 by natalieyan        #+#    #+#             */
/*   Updated: 2025/07/26 17:33:43 by natalieyan       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_exit(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

void	free_list(char **nums, int nums_count)
{
	int	i;

	i = 0;
	while (i < nums_count)
	{
		free(nums[i]);
		i++;
	}
	free(nums);
}

void	free_stack(t_stack **a)
{
	t_stack	*tmp;

	while (*a)
	{
		tmp = (*a)->next;
		free(*a);
		(*a) = tmp;
	}
}

void	error_exit_with_free(char **nums, int nums_count, t_stack **a)
{
	free_list(nums, nums_count);
	free_stack(a);
	error_exit();
}
