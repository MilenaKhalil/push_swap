/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main_bonus.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mikhalil <mikhalil@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/03 21:12:16 by mikhalil      #+#    #+#                 */
/*   Updated: 2023/07/18 20:46:52 by mikhalil      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"
#include "libft/libft.h"

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
			*a = ft_lstnew(prev);
		else
			ft_lstadd_front(a, ft_lstnew(prev));
		i--;
	}
	return (sorted);
}

char	*match_command(t_list **a, t_list **b, char *com)
{
	if (!ft_strncmp("sa\n", com, 3) || !ft_strncmp("sb\n", com, 3)
		|| !ft_strncmp("ss\n", com, 3) || !ft_strncmp("ra\n", com, 3)
		|| !ft_strncmp("rb\n", com, 3) || !ft_strncmp("rr\n", com, 3)
		|| !ft_strncmp("pa\n", com, 3) || !ft_strncmp("pb\n", com, 3)
		|| !ft_strncmp("rra\n", com, 4) || !ft_strncmp("rrb\n", com, 4)
		|| !ft_strncmp("rrr\n", com, 4))
	{
		com[ft_strlen(com) - 1] = 0;
		return (com);
	}
	else if (b)
		ft_lstlast(*a)->next = *b;
	if (com)
		free(com);
	bad_exit(a);
	return (0);
}

int	is_sorted(t_list *a, t_list *b)
{
	int	prev;

	if (b)
		return (0);
	prev = a->content;
	a = a->next;
	while (a)
	{
		if (prev > a->content)
			return (0);
		prev = a->content;
		a = a->next;
	}
	return (1);
}

void	checker(t_list **a, t_list **b)
{
	char	*com;

	com = get_next_line(0);
	while (com)
	{
		inter_command(a, b, match_command(a, b, com), "");
		free(com);
		com = get_next_line(0);
	}
	if (is_sorted(*a, *b))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
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
	get_input(i, clean, &stack_a);
	check_dup(&stack_a);
	checker(&stack_a, &stack_b);
	if (flag)
		free_mem(clean, i - 1);
	good_exit(&stack_a);
}
