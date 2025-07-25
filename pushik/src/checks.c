/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natalieyan <natalieyan@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 13:16:37 by natalieyan        #+#    #+#             */
/*   Updated: 2025/07/24 22:21:44 by natalieyan       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	check_for_dup(long tmp, char **av, int i)
{
	i++;
	while (av[i])
	{
		if (ft_atoi(av[i]) == tmp)
			return (1);
		i++;
	}
	return (0);
}

void	check_and_push(char **av, t_stack **a)
{
	int		i;
	long	tmp;

	i = 0;
	while (av[++i])
	{
		tmp = ft_atoi(av[i]);
		if (!ft_str_is_num(av[i]) || check_for_dup(tmp, av, i) || (tmp > INT_MAX
				|| tmp < INT_MIN))
		{
			free_stack(a);
			write(2, "Error\n", 6);
			exit(EXIT_FAILURE);
		}
		if (!*a)
			*a = add_number_to_stack(tmp);
		else
			add_tail_to_stack(a, add_number_to_stack(tmp));
	}
}

void	define_sort(t_stack **a, t_stack **b)
{
	if (!*a || !(*a)->next)
		return ;
	else if (stack_size(a) == 2)
		sort_stack_of_2(a);
	else if (stack_size(a) <= 3)
		sort_stack_of_3(a);
	else if (stack_size(a) <= 5)
		sort_stack_of_5(a, b);
	else
		sort_big_stack(a, b);
}

int	stack_is_sorted(t_stack **stack)
{
	int		prev_val;
	t_stack	*curr;

	if (!stack || !(*stack)->next)
		return (1);
	prev_val = (*stack)->val;
	curr = (*stack)->next;
	while (curr)
	{
		if (curr->val < prev_val)
			return (0);
		prev_val = curr->val;
		curr = curr->next;
	}
	return (1);
}
