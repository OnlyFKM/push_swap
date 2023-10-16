/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frcastil <frcastil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 11:06:12 by frcastil          #+#    #+#             */
/*   Updated: 2023/10/16 12:34:16 by frcastil         ###   ########.fr       */
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
	int				size;
	int				cost_a;
	int				cost_b;
	struct s_stack	*next;
}					t_stack;

// main.c
int				main(int argc, char *argv[]);
char			**ft_check_args(int argc, char *argv[]);
void			ft_init_program(t_stack ***stack_a, t_stack ***stack_b);

// checkers.c
void			ft_check_conditions(char *argv[]);
int				ft_check_correct_digits(char **argv);
int				ft_check_duplicates(char **argv);
void			ft_check_conditions_2(char **str);

// stack.c
int				ft_transfer_stack(char *value_str, t_stack **stack);

// utils.c
int				ft_stacksize(t_stack *stack);
void			ft_free_str(char **str);
int				ft_sorted_list(t_stack **stack);
void			ft_stackadd_back(t_stack **stack, t_stack *new);
void			*ft_stacklast(t_stack *stack);

// push.c
void			ft_push(t_stack **stack_one, t_stack **stack_two);
void			ft_push_a(t_stack **stack_a, t_stack **stack_b);
void			ft_push_b(t_stack **stack_b, t_stack **stack_a);

// swap.c
void			ft_swap(t_stack **stack);
void			ft_swap_a(t_stack **stack_a);
void			ft_swap_b(t_stack **stack_b);
void			ft_swap_s(t_stack **stack_a, t_stack **stack_b);

// rotate.c
void			ft_rotate(t_stack **stack);
void			ft_rotate_a(t_stack **stack_a);
void			ft_rotate_b(t_stack **stack_b);
void			ft_rotate_s(t_stack **stack_a, t_stack **stack_b);

// reverse_rotate.c
void			ft_reverse_rotate(t_stack **stack);
void			ft_reverse_rotate_a(t_stack **stack_a);
void			ft_reverse_rotate_b(t_stack **stack_b);
void			ft_reverse_rotate_ss(t_stack **stack_a, t_stack **stack_b);

// algorithm.c
void			ft_order_3(t_stack **stack_a);
void			ft_best_algorithm(t_stack **stack_a, t_stack **stack_b, int i);

#endif