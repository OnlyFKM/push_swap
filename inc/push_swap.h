/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frcastil <frcastil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 11:06:12 by frcastil          #+#    #+#             */
/*   Updated: 2023/10/25 10:44:41 by frcastil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"

# define FALSE 0
# define TRUE 1

# define MIN_INT -2147483648
# define MAX_INT 2147483647

typedef struct s_stack
{
	int				values;
	int				index;
	int				pos;
	int				target;
	int				cost_a;
	int				cost_b;
	struct s_stack	*next;
}					t_stack;

// main.c
int			main(int argc, char *argv[]);
char		**ft_check_args(int argc, char *argv[]);
void		ft_init_program(t_stack ***stack_a, t_stack ***stack_b);
void		ft_free_stack(t_stack **stack);

// checkers.c
void		ft_check_conditions(char *argv[]);
int			ft_check_correct_digits(char **argv);
int			ft_check_duplicates(char **argv);
void		ft_check_conditions_2(char **str);

// stack.c
int			ft_transfer_stack(char *value_str, t_stack **stack);

// utils.c
int			ft_stacksize(t_stack *stack);
void		ft_free_str(char **str);
int			ft_sorted_list(t_stack **stack);
void		ft_stackadd_back(t_stack **stack, t_stack *new);
void		*ft_stacklast(t_stack *stack);

// position.c
void		ft_put_position(t_stack **stack);
void		ft_put_index(t_stack **stack);
t_stack		*ft_min_index(t_stack **stack_a);
t_stack		*ft_max_index(t_stack **stack_a);
void		ft_calculate_target(t_stack *copy_a, t_stack *copy_b, int *rest);

// cost.c
void		ft_calculate_cost(t_stack **stack_a, t_stack **stack_b);
t_stack		*ft_calculate_cheapest(t_stack **stack_b);
int			ft_abs_value(int values);
int			ft_check_par(int size);

// push.c
void		ft_push(t_stack **stack_one, t_stack **stack_two);
void		ft_push_a(t_stack **stack_a, t_stack **stack_b, int flag);
void		ft_push_b(t_stack **stack_b, t_stack **stack_a, int flag);

// swap.c
void		ft_swap(t_stack **stack);
void		ft_swap_a(t_stack **stack_a, int flag);
void		ft_swap_b(t_stack **stack_b, int flag);
void		ft_swap_s(t_stack **stack_a, t_stack **stack_b, int flag);

// rotate.c
void		ft_rotate(t_stack **stack);
void		ft_rotate_a(t_stack **stack_a, int flag);
void		ft_rotate_b(t_stack **stack_b, int flag);
void		ft_rotate_r(t_stack **stack_a, t_stack **stack_b, int flag);

// reverse_rotate.c
void		ft_reverse_rotate(t_stack **stack);
void		ft_reverse_rotate_a(t_stack **stack_a, int flag);
void		ft_reverse_rotate_b(t_stack **stack_b, int flag);
void		ft_reverse_rotate_r(t_stack **stack_a, t_stack **stack_b, int flag);

// algorithm.c
void		ft_best_algorithm(t_stack **stack_a, t_stack **stack_b, int i);
void		ft_rotate_a_if(t_stack **stack_a, int *cost_a);
void		ft_rotate_b_if(t_stack **stack_b, int *cost_b);

// steps.c
void		ft_first_step(t_stack **stack_a, t_stack **stack_b);
void		ft_second_step(t_stack **stack_a);
void		ft_third_step(t_stack **stack_a, t_stack **stack_b);
void		ft_fourth_step(t_stack **stack_a, t_stack **stack_b);
void		ft_last_step(t_stack **stack_a);

// checker_bonus.c
int			main(int argc, char *argv[]);
void		ft_init_program(t_stack ***stack_a, t_stack ***stack_b);
int			ft_messages(t_stack **stack_a, t_stack **stack_b, char *order);
void		ft_checker(t_stack **stack_a, t_stack **stack_b);

// utils_bonus.c
void		ft_final_check(t_stack **stack_a, t_stack **stack_b);
void		ft_free_stack(t_stack **stack);

#endif