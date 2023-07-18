/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mikhalil <mikhalil@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/03 21:12:16 by mikhalil      #+#    #+#                 */
/*   Updated: 2023/07/18 18:16:33 by mikhalil      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	itoa(t_list **a, char *str)
{
	long	res;
	int		min;
	int		i;

	res = 0;
	min = -1;
	i = 0;
	if (!str[0] || (str[0] == '-' && !str[1]))
		bad_exit(a);
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
			bad_exit(a);
		if (res * min > INT_MAX || res * min < INT_MIN)
			bad_exit(a);
		i++;
	}
	return (res * min);
}

void	check_dup(t_list **stack_a)
{
	t_list	*now;
	t_list	*a;

	a = *stack_a;
	if (!a || !(a->next))
		return ;
	while (a->next)
	{
		now = a->next;
		while (now)
		{
			if (now->content == a->content)
				bad_exit(stack_a);
			now = now->next;
		}
		a = a->next;
	}
}

char	**clean_input(char **argv)
{
	int		i;
	char	**test;

	i = 0;
	while (argv[1][i])
	{
		if (argv[1][i] == ' ')
		{
			test = ft_split(argv[1], ' ');
			if (!(*test))
				bad_exit(NULL);
			test[0][0]--;
			break ;
		}
		i++;
	}
	if (!argv[1][i])
		test = &argv[1];
	return (test);
}

void	inter_command(t_list **a, t_list **b, char *com, char *str)
{
	if (com[0] == 's')
		swaps(a, b, com, str);
	else if (com[0] == 'p')
		push(a, b, com, str);
	else
		rotations(a, b, com, str);
}
