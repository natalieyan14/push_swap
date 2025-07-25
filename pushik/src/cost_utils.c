/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natalieyan <natalieyan@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 13:16:28 by natalieyan        #+#    #+#             */
/*   Updated: 2025/07/24 22:21:48 by natalieyan       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	free_cost_tab(t_cost_tab **table)
{
	t_cost_tab	*tmp;

	if (!*table)
		return ;
	while (*table)
	{
		tmp = (*table)->next;
		(*table)->bf = 0;
		(*table)->val = 0;
		(*table)->cost = 0;
		free(*table);
		(*table) = tmp;
	}
}

t_cost_tab	*add_cost(int val, int bf, int val_cost)
{
	t_cost_tab	*new_node;

	new_node = (t_cost_tab *)malloc(sizeof(t_cost_tab));
	if (!new_node)
		return (NULL);
	new_node->val = val;
	new_node->bf = bf;
	new_node->cost = val_cost;
	new_node->next = NULL;
	return (new_node);
}

void	add_tail_to_cost_table(t_cost_tab **table_head, t_cost_tab *new_node)
{
	if (!table_head)
		return ;
	if (!*table_head)
		*table_head = new_node;
	else
		(find_last_cost(*table_head))->next = new_node;
}

t_cost_tab	*find_last_cost(t_cost_tab *table)
{
	if (!table)
		return (NULL);
	while (table->next)
		table = table->next;
	return (table);
}
