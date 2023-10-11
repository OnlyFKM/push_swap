/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frcastil <frcastil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 12:07:45 by frcastil          #+#    #+#             */
/*   Updated: 2023/10/11 16:57:37 by frcastil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_init_program(t_stack ***stack_a, t_stack ***stack_b)
{
	*stack_a = (t_stack **)malloc(sizeof(t_stack *));
	if (*stack_a == NULL)
	{
		ft_printf("Error\nFailed to allocate memory\n");
		exit(EXIT_FAILURE);
	}
	**stack_a = NULL;
	*stack_b = (t_stack **)malloc(sizeof(t_stack *));
	if (*stack_b == NULL)
	{
		free(*stack_a);
		ft_printf("Error\nFailed to allocate memory\n");
		exit(EXIT_FAILURE);
	}
	**stack_b = NULL;
}

char	**ft_check_args(int argc, char *argv[])
{
	char	**str;
	int		new_argc;
	int		a;

	a = 0;
	new_argc = 0;
	if (argc < 2)
	{
		ft_printf("Error\nThere is not a valid argue\n");
		exit(EXIT_FAILURE);
	}
	else if (argc == 2)
	{
		str = ft_split(argv[1], ' ');
		while (str[new_argc])
		{
			ft_printf("%s\n", str[new_argc]);
			new_argc++;
		}
		ft_printf("%d\n", new_argc);
		if (str == NULL)
		{
			ft_printf("Error\nFailed to split arguments\n");
			exit(EXIT_FAILURE);
		}
		ft_check_conditions_2(str);
		return (str);
	}
	else
	{
		while (a++ < argc - 1)
			ft_printf("%s\n", argv[a]);
		ft_check_conditions(argv);
		return (argv);
	}
}

int	main(int argc, char *argv[])
{
	t_stack	**stack_a;
	t_stack	**stack_b;
	char	**str;
	int		i;

	ft_init_program(&stack_a, &stack_b);
	str = ft_check_args(argc, argv);
	i = 1;
	while (str[i] != NULL)
	{
		if (!ft_transfer_stack(str[i], stack_a))
		{
			ft_printf("Error\nFailed to add elements to stack\n");
			exit(EXIT_FAILURE);
		}
		i++;
	}
	ft_sorted_list(stack_a);
	/* 	ft_free_str(str); */
	return (0);
}
