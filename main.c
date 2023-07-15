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

#include "push_swap.h"

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
			bad_exit(a);
		if (res * min > INT_MAX || res * min < INT_MIN)
			bad_exit(a);
		i++;
	}
	return (res * min);
}

int	get_input(int argc, char **argv, t_list **a)
{
	int	i;
	int	sorted;
	int	prev;
	int	check;

    i = argc - 1;
	sorted = 1;
	while (i >= 1)
	{
		check = itoa(a, argv[i]);
		if (!(*a))
			*a = ft_lstnew(check);
		else
			ft_lstadd_front(a, ft_lstnew(check));
        if (i != argc - 1 && prev < check)
            sorted = 0;
        if (i != argc - 1 && prev == check)
            bad_exit(a);
        prev = check;
		i--;
	}
    return (sorted);
}

void    check_dup(t_list **stack_a)
{
    t_list  *now;
    t_list  *a;

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

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;
    int     sorted;

	stack_a = NULL;
	stack_b = NULL;
	if (argc == 1)
		return (0);
	sorted = get_input(argc, argv, &stack_a);
    if (sorted)
        good_exit(&stack_a);
    check_dup(&stack_a);
	sort_stack(&stack_a, &stack_b);
    good_exit(&stack_a);
}
