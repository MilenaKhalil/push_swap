/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main2.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mikhalil <mikhalil@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/03 21:12:16 by mikhalil      #+#    #+#                 */
/*   Updated: 2023/07/06 19:13:53 by mikhalil      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <limits.h>

void	bad_exit(t_list **a, char *str)
{
	ft_lstclear(a);
	write(2, str, ft_strlen(str));
	exit(1);
}

int	itoa(t_list **a, char *str)
{
	long	res;
	int		min;
	int		i;

	res = 0;
	min = -1;
	i = 0;
	if (str[i] == '-')
	{
		min = 1;
		i++;
	}
	while (str[i])
	{
		if (str[i] <= '9' && str[i] >= '0')
			res = res * 10 - (str[i] - '0');
		else
			bad_exit(a, "Wrong input\n");
		if (res * min > INT_MAX || res * min < INT_MIN)
			bad_exit(a, "Wrong input\n");
		i++;
	}
	return (res * min);
}

void	get_input(int argc, char **argv, t_list **a)
{
	int	i;
	int	sorted;
	int	prev;
	int	check;

	i = 1;
	sorted = 1;
	while (i < argc)
	{
		check = itoa(a, argv[i]);
		if (!(*a))
		{
			*a = ft_lstnew(check);
			prev = check;
		}
		else
		{
			
			ft_lstadd_front(a, ft_lstnew(check));
		}
		i++;
	}
}

void	print_stack(t_list *ab)
{
	int	i;

	i = 0;
	while (ab)
	{
		printf("el[%d] = %d ", i, ab->content);
		ab = ab->next;
		i++;
	}
	printf("\n");
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc == 1)
		return (0);
	//(void) argv;
	get_input(argc, argv, &stack_a);
	print_stack(stack_a);
	return (0);
}