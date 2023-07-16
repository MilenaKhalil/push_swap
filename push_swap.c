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

void    sort_three(t_list **stack_a)
{
    t_list  *a;
    t_list  *ne;
    t_list  *nene;

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

void    insert_el(t_list **a, t_list **b, int pos_a, int pos_b)  // просто ra и просто rb
{
    while (pos_a)
    {
        inter_command(a, b, "ra", "ra\n");
        pos_a--;
    }
    while (pos_b)
    {
        inter_command(a, b, "rb", "rb\n");
        pos_b--;
    }
    inter_command(a, b, "pa", "pa\n");
}

void    stack_rot(t_list **a, t_list **b, int iter, int i)
{
    int size_a;

    size_a = ft_lstsize(*a);
    while ((*a)->content != iter)
    {
        if (i > size_a / 2)
            inter_command(a, b, "rra", "rra\n");
        else
            inter_command(a, b, "ra", "ra\n");
    }
}

int    find_place(t_list **a, int elem, int min, int max)
{
    int     i;
    t_list  *iter;
    t_list  *prev;

    i = 0;
    iter = *a;
    prev = ft_lstlast(*a);
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
    {
        while (iter->content != min)
        {
            iter = iter->next;
            i++;
        }
    }
    return (i);
}

int find_best(t_list **a, t_list *b, int min, int max)
{
    int b_pos;
    int best;
    int best_pos;

    best = -1;
    b_pos = 0;
    while (b)
    {
        if (best == -1 || best > find_place(a, b->content, min, max) + b_pos)
        {
            best_pos = b_pos;
            best = find_place(a, b->content, min, max) + b_pos;
        }
        b = b->next;
        b_pos++;
    }
    //return best_pos;
    return (0);
}

int     get_elem(t_list *stack, int pos)
{
    while (pos)
    {
        stack = stack->next;
        pos--;
    }
    return (stack->content);
}

void    real_sort(t_list **a, t_list **b)
{
    t_list  *temp;
    int     size_a;
    int     min;
    int     max;
    int     pos_a;
    int     pos_b;
    int     i;

    size_a = ft_lstsize(*a);
    i = 0;
    while (size_a > 3)
    {
        inter_command(a, b, "pb", "pb\n");
        size_a--;
    }
    sort_three(a);
    min = (*a)->content;
    max = (*a)->next->next->content;
    while (*b)
    {
        pos_b = find_best(a, *b, min, max);
        pos_a = find_place(a, get_elem(*b, pos_b), min, max);//(*b)->content, min, max);
        if (get_elem(*b, pos_b) > max)
            max = get_elem(*b, pos_b);
        else if (get_elem(*b, pos_b) < min)
            min = get_elem(*b, pos_b);
        /*if ((*b)->content > max)
            max = (*b)->content;
        else if ((*b)->content < min)
            min = (*b)->content;*/
        insert_el(a, b, pos_a, pos_b);
    }
    temp = *a;
    while (temp->content != min)
    {
        temp = temp->next;
        i++;
    }
    stack_rot(a, b, min, i);
}

void    sort_stack(t_list **stack_a, t_list **stack_b)              // лучше передавать сюда структуру!!!
{
    int     length;

    (void) stack_b;
    length = ft_lstsize(*stack_a);
    if (length == 2)
        swap(stack_a, "sa\n");
    else if (length == 3)
        sort_three(stack_a);
    else
        real_sort(stack_a, stack_b);                                // нужно проверять числа на одинаковость!!!
}
