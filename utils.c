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

int     get_elem(t_list *stack, int pos)
{
    while (pos)
    {
        stack = stack->next;
        pos--;
    }
    return (stack->content);
}

int     get_pos(t_list *stack, int elem)
{
    int pos;

    pos = 0;
    while (stack->content != elem)
    {
        stack = stack->next;
        pos++;
    }
    return (pos);
}

int     maximum(int a, int b)
{
    if (a > b)
        return (a);
    return (b);
}

void	bad_exit(t_list **a)
{
	ft_lstclear(a);
	write(2, "Error\n", 6);
	exit(1);
}

void	good_exit(t_list **a)
{
	ft_lstclear(a);
	exit(0);
}

void    inter_command(t_list **a, t_list **b, char *com, char *str)
{
    if (com[0] == 's')
        swaps(a, b, com, str);
    else if (com[0] == 'p')
        push(a, b, com, str);
    else
        rotations(a, b, com, str);
}
