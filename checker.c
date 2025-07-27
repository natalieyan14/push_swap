/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natalieyan <natalieyan@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 17:33:48 by natalieyan        #+#    #+#             */
/*   Updated: 2025/07/26 17:33:50 by natalieyan       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "push_swap.h"

int	valid_instruct(char *str, t_stack **a, t_stack **b)
{
	if (ft_strlen(str) < 2)
		return (0);
	if (str[0] == 'p' && push_bonus(a, b, str))
		return (1);
	else if (str[0] == 's' && swap_bonus(a, b, str))
		return (1);
	else if (str[0] == 'r' && (rotate_bonus(a, b, str) || rev_rotate_bonus(a, b,
				str)))
		return (1);
	else
		return (0);
}

void	get_instructs(t_stack **a, t_stack **b)
{
	char	*str;

	while (1)
	{
		str = get_next_line(0);
		if (valid_instruct(str, a, b) == 0)
		{
			if (!ft_strlen(str))
				break ;
			free_stack(a);
			error_exit();
		}
		free(str);
	}
}

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
	get_instructs(&a, &b);
	if (!sorted(a) || stack_len(b))
		write(1, "KO\n", 3);
	else
		write(1, "OK\n", 3);
	free_stack(&a);
	return (0);
}
