/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   commands.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: mikhalil <mikhalil@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/03 21:12:16 by mikhalil      #+#    #+#                 */
/*   Updated: 2023/07/18 14:33:02 by mikhalil      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_list **stack, char *str)
{
	t_list	*second;

	if (!(*stack) || !(*stack)->next)
		return ;
	second = (*stack)->next;
	(*stack)->next = second->next;
	second->next = (*stack);
	(*stack) = second;
	write(1, str, ft_strlen(str));
}

void	swaps(t_list **stack_a, t_list **stack_b, char *com, char *str)
{
	if (com[1] == 'a')
		swap(stack_a, str);
	else if (com[1] == 'b')
		swap(stack_b, str);
	else
	{
		swap(stack_a, "");
		swap(stack_b, "");
		write(1, str, ft_strlen(str));
	}
}

void	push(t_list **stack_a, t_list **stack_b, char *com, char *str)
{
	t_list	*second;

	if (!ft_strncmp(com, "pb", 2))
	{
		if (!(*stack_a))
			return ;
		second = (*stack_a)->next;
		(*stack_a)->next = (*stack_b);
		(*stack_b) = (*stack_a);
		(*stack_a) = second;
	}
	else
	{
		if (!(*stack_b))
			return ;
		second = (*stack_b)->next;
		(*stack_b)->next = (*stack_a);
		(*stack_a) = (*stack_b);
		(*stack_b) = second;
	}
	write(1, str, ft_strlen(str));
}

void	rotate(t_list **stack, int rev, char *str)
{
	t_list	*last;
	t_list	*temp;

	if (!(*stack) || !(*stack)->next)
		return ;
	last = ft_lstlast((*stack));
	if (!rev)
	{
		temp = (*stack)->next;
		last->next = (*stack);
		(*stack)->next = NULL;
		(*stack) = temp;
	}
	else
	{
		temp = (*stack);
		while (temp->next->next)
			temp = temp->next;
		temp->next = NULL;
		last->next = (*stack);
		(*stack) = last;
	}
	write(1, str, ft_strlen(str));
}

void	rotations(t_list **a, t_list **b, char *com, char *str)
{
	int	rev;

	rev = ft_strlen(com) - 2;
	if (com[1 + rev] == 'a')
		rotate(a, rev, str);
	else if (com[1 + rev] == 'b')
		rotate(b, rev, str);
	else
	{
		rotate(a, rev, "");
		rotate(b, rev, "");
		write(1, str, ft_strlen(str));
	}
}
