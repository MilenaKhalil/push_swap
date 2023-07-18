/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils_mand.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mikhalil <mikhalil@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/03 21:12:16 by mikhalil      #+#    #+#                 */
/*   Updated: 2023/07/18 16:37:20 by mikhalil      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_elem(t_list *stack, int pos)
{
	while (pos)
	{
		stack = stack->next;
		pos--;
	}
	return (stack->content);
}

int	get_pos(t_list *stack, int elem)
{
	int	pos;

	pos = 0;
	while (stack->content != elem)
	{
		stack = stack->next;
		pos++;
	}
	return (pos);
}

int	maximum(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}
