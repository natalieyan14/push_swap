/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natalieyan <natalieyan@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 17:32:34 by natalieyan        #+#    #+#             */
/*   Updated: 2025/07/26 17:32:37 by natalieyan       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	my_log2(int x)
{
	int	i;
	int	count;

	i = 2;
	count = 0;
	while (i < x)
	{
		count++;
		i *= 2;
	}
	return (count + 1);
}

int	my_log5(int x)
{
	int	i;
	int	count;

	i = 5;
	count = 0;
	while (i < x)
	{
		count++;
		i *= 5;
	}
	return (count + 1);
}
