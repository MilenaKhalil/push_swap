/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mikhalil <mikhalil@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/03 21:12:16 by mikhalil      #+#    #+#                 */
/*   Updated: 2023/07/16 19:59:09 by mikhalil      ########   odam.nl         */
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

void	stack_rot(t_list **stack, int pos, char *com, char *rev)
{
	int     size;
    int     elem;

    elem = get_elem(*stack, pos);
	size = ft_lstsize(*stack);
	while ((*stack)->content != elem)
	{
		if (pos > size / 2)
			rotate(stack, 1, rev);
		else
			rotate(stack, 0, com);
	}
}

void	insert_el(t_list **a, t_list **b, int pos_a, int pos_b)
{
    int size_a;
    int size_b;

    size_a = ft_lstsize(*a);
    size_b = ft_lstsize(*b);
    if ((pos_a <= size_a / 2) && (pos_b <= size_b / 2))
    {
        while (pos_a && pos_b)
        {
            rotations(a, b, "rr", "rr\n");
            pos_a--;
            pos_b--;
        }
    }
    else if ((pos_a > size_a / 2) && (pos_b > size_b / 2))
    {
        while (pos_a && pos_b)
        {
            rotations(a, b, "rrr", "rrr\n");
            pos_a = (pos_a + 1) % ft_lstsize(*a);
            pos_b = (pos_b + 1) % ft_lstsize(*b);
        }
    }
    stack_rot(a, pos_a, "ra\n", "rra\n");
    stack_rot(b, pos_b, "rb\n", "rrb\n");
	inter_command(a, b, "pa", "pa\n");
}

int	find_place(t_list *iter, int elem, int min, int max)
{
	int		i;
	t_list	*prev;

	i = 0;
	prev = ft_lstlast(iter);
	if (elem > min && elem < max)
	{
		while (!(iter->content > elem && elem > prev->content))
		{
		    i++;
	        prev = iter;
	        iter = iter->next;
	    }
	}
	else
        return (get_pos(iter, min));
	return (i);
}

int analize(t_list *a, t_list *b, int pos_a, int pos_b)
{
    int size_a;
    int size_b;

    size_a = ft_lstsize(a);
    size_b = ft_lstsize(b);
    if ((pos_a <= size_a / 2) && (pos_b <= size_b / 2))
        return (maximum(pos_a, pos_b));
    if ((pos_a > size_a / 2) && (pos_b > size_b / 2))
        return (maximum(size_a - pos_a, size_b - pos_b));
    if (pos_a > size_a / 2)
        pos_a = size_a - pos_a;
    if (pos_b > size_b / 2)
        pos_b = size_b - pos_b;
    return (pos_a + pos_b);
}

int find_best(t_list *a, t_list *b, int min, int max)
{
    t_list  *head;
    int     a_pos;
    int     b_pos;
    int     best;
    int     best_pos;

    best = -1;
    b_pos = 0;
    head = b;
    while (b)
    {
        a_pos = find_place(a, b->content, min, max);
        if (best == -1 || best > analize(a, head, a_pos, b_pos))
        {
            best_pos = b_pos;
            best = analize(a, head, a_pos, b_pos);
        }
        b = b->next;
        b_pos++;
    }
    return (best_pos);
}

void    real_sort(t_list **a, t_list **b)
{
    int     min;
    int     max;
    int     pos_a;
    int     pos_b;

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

void    sort_stack(t_list **stack_a, t_list **stack_b)
{
    int     length;

    (void) stack_b;
    length = ft_lstsize(*stack_a);
    if (length == 2)
        swap(stack_a, "sa\n");
    else if (length == 3)
        sort_three(stack_a);
    else
        real_sort(stack_a, stack_b);
}
