/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natalieyan <natalieyan@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 17:29:19 by natalieyan        #+#    #+#             */
/*   Updated: 2025/07/31 01:37:46 by natalieyan       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_sortdata
{
	int				min;
	int				offset;
	int				rb_count;
}					t_sortdata;

typedef struct s_stack
{
	int				data;
	int				index;
	struct s_stack	*next;
}					t_stack;

int					ft_strlen(char *s);
int					ft_isspace(char c);
int					ft_words_count(char *s);
int					ft_strcmp(const char *s1, const char *s2);
int					my_log2(int x);
int					my_log5(int x);
int					stack_len(t_stack *a);
void				free_list(char **nums, int nums_count);
void				free_stack(t_stack **a);

char				**ft_split(char const *s);
void				validation(char **args);
int					check_for_valid_num(t_stack *a, char *str);
void				init_stack(char **args, t_stack **a);

void				setting_indexes(t_stack **a);
int					sorted(t_stack *a);

void				error_exit(void);
void				error_exit_with_free(char **nums, int nums_count,
						t_stack **a);

void				swap(t_stack **a);
void				sa(t_stack **a);
void				sb(t_stack **b);
void				ss(t_stack **a, t_stack **b);

void				push(t_stack **a, t_stack **b);
void				pa(t_stack **a, t_stack **b);
void				pb(t_stack **a, t_stack **b);

void				rotate(t_stack **a);
void				ra(t_stack **a);
void				rb(t_stack **b);
void				rr(t_stack **a, t_stack **b);

void				rev_rotate(t_stack **a);
void				rra(t_stack **a);
void				rrb(t_stack **b);
void				rrr(t_stack **a, t_stack **b);

int					push_bonus(t_stack **a, t_stack **b, char *str);
int					swap_bonus(t_stack **a, t_stack **b, char *str);
int					rotate_bonus(t_stack **a, t_stack **b, char *str);
int					rev_rotate_bonus(t_stack **a, t_stack **b, char *str);

void				simple_sort(t_stack **a, t_stack **b);
void				butterfly_sort(t_stack **a, t_stack **b);
void				sort_in_b(t_stack **a, t_stack **b);
void				sort_in_a(t_stack **a, t_stack **b);
int					get_position(t_stack *stack, int index);

void				print_stacks(t_stack *a, t_stack *b);

void				butterfly_sort(t_stack **a, t_stack **b);
int					calc_mid(t_stack *a);
int					get_chunks(int total_len);
void				push_chunks_to_b(t_stack **a, t_stack **b);
void				push_back_to_a(t_stack **a, t_stack **b);
int					get_max_index(t_stack *stack);
int					get_pos(t_stack *stack, int index);

#endif
