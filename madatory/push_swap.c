/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natalieyan <natalieyan@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 17:30:14 by natalieyan        #+#    #+#             */
/*   Updated: 2025/07/29 21:36:45 by natalieyan       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_stack	*a;
	t_stack	*b;

	if (argc < 2)
		return (0);
	validation(argv);
	a = NULL;
	init_stack(argv, &a);
	b = NULL;
	setting_indexes(&a);
	if (!sorted(a))
	{
		if (stack_len(a) <= 6)
			simple_sort(&a, &b);
		else
			butterfly_sort(&a, &b);
	}
	free_stack(&a);
	return (0);
}
