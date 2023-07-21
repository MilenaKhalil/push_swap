/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mikhalil <mikhalil@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/03 21:12:16 by mikhalil      #+#    #+#                 */
/*   Updated: 2023/07/21 16:56:37 by mikhalil      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_list **stack_a)
{
	t_list	*a;
	t_list	*ne;
	t_list	*nene;

	a = (*stack_a);
	ne = a->next;
	nene = a->next->next;
	if (a->content < ne->content && ne->content < nene->content)
		return ;
	if (a->content > ne->content && a->content > nene->content)
		rotate(stack_a, 0, "ra\n");
	else if (ne->content > a->content && ne->content > nene->content)
		rotate(stack_a, 1, "rra\n");
	if ((*stack_a)->content > (*stack_a)->next->content)
		swap(stack_a, "sa\n");
}

void	real_sort(t_list **a, t_list **b)
{
	int	min;
	int	max;
	int	pos_a;
	int	pos_b;

	while (ft_lstsize(*a) > 3)
		inter_command(a, b, "pb", "pb\n");
	sort_three(a);
	min = (*a)->content;
	max = (*a)->next->next->content;
	while (*b)
	{
		pos_b = find_best(*a, *b, min, max);
		pos_a = find_place(*a, get_elem(*b, pos_b), min, max);
		if (get_elem(*b, pos_b) > max)
			max = get_elem(*b, pos_b);
		else if (get_elem(*b, pos_b) < min)
			min = get_elem(*b, pos_b);
		insert_el(a, b, pos_a, pos_b);
	}
	stack_rot(a, get_pos(*a, min), "ra\n", "rra\n");
}

void	sort_stack(t_list **stack_a, t_list **stack_b)
{
	int	length;

	(void) stack_b;
	length = ft_lstsize(*stack_a);
	if (length == 2)
		swap(stack_a, "sa\n");
	else if (length == 3)
		sort_three(stack_a);
	else
		real_sort(stack_a, stack_b);
}

int	get_input(int argc, char **clean, t_list **a)
{
	int		i;
	int		sorted;
	int		prev;
	t_list	*temp;

	i = argc - 1;
	sorted = 1;
	while (i >= 0)
	{
		if (i != argc - 1 && prev < itoa(a, clean[i]))
			sorted = 0;
		if (i != argc - 1 && prev == itoa(a, clean[i]))
			bad_exit(a);
		prev = itoa(a, clean[i]);
		temp = ft_lstnew(prev);
		if (!temp)
			bad_exit(a);
		if (!(*a))
			*a = temp;
		else
			ft_lstadd_front(a, temp);
		i--;
	}
	return (sorted);
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;
	char	**clean;
	int		i;
	int		flag;

	stack_a = NULL;
	stack_b = NULL;
	if (argc == 1)
		return (0);
	clean = clean_input(argv);
	flag = argv[1][0] - clean[0][0];
	if (flag)
		clean[0][0]++;
	i = 0;
	while (clean[i])
		i++;
	if (get_input(i, clean, &stack_a))
		good_exit(&stack_a);
	check_dup(&stack_a);
	sort_stack(&stack_a, &stack_b);
	if (flag)
		free_mem(clean, i - 1);
	good_exit(&stack_a);
}
