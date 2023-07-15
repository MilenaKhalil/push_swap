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

/*int is_sorted(t_list *a, int rev)
{
    int prev;

    if (!a || !(a->next))
        return (1);
    prev = a->content;
    a = a->next;
    while (a)
    {
        if ((!rev && prev > a->content)
                || (rev && prev < a->content))
            return (0);
        prev = a->content;
        a = a->next;
    }
    return (1);
}*/

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

void    stack_rot(t_list **a, t_list **b, t_list *iter, int i)
{
    int size_a;

    size_a = ft_lstsize(*a);
    while ((*a)->content != iter->content)
    {
        if (i > size_a / 2)
            inter_command(a, b, "rra", "rra\n");
        else
            inter_command(a, b, "ra", "ra\n");
    }
}

void    find_place(t_list **a, t_list **b, t_list **min, t_list **max)
{
    int     i;
    t_list  *iter;
    t_list  *prev;

    i = 0;
    iter = *a;
    prev = ft_lstlast(*a);
    if ((*b)->content > (*min)->content && (*b)->content < (*max)->content)
    {
        while (!(iter->content > (*b)->content && (*b)->content > prev->content))
        {
            i++;
            prev = iter;
            iter = iter->next;
        }
        stack_rot(a, b, iter, i);
    }
    else
    {
        while (iter->content != (*min)->content)
        {
            iter = iter->next;
            i++;
        }
        stack_rot(a, b, iter, i);
        if ((*b)->content > (*max)->content)
            *max = *b;
        else
            *min = *b;
    }
}

void    real_sort(t_list **a, t_list **b)
{
    int     size_a;
    t_list  *min;
    t_list  *max;
    int     i;

    size_a = ft_lstsize(*a);
    i = 0;
    while (size_a > 3)
    {
        inter_command(a, b, "pb", "pb\n");
        size_a--;
    }
    sort_three(a);
    min = (*a);
    max = (*a)->next->next;
    while (*b)
    {
        find_place(a, b, &min, &max);
        inter_command(a, b, "pa", "pa\n");
    }
    max = *a;
    while (max->content != min->content)
    {
        max = max->next;
        i++;
    }
    stack_rot(a, b, min, i);
}

void    sort_stack(t_list **stack_a, t_list **stack_b)           // лучше передавать сюда структуру!!!
{
    int     length;
    //char    **commands[10][3];

    (void) stack_b;
    length = ft_lstsize(*stack_a);
    if (length == 2)
        swap(stack_a, "sa\n");
    else if (length == 3)
        sort_three(stack_a);
//    else if (length <= 5)
//        sort_some(stack_a, stack_b);                   // нужно проверять числа на одинаковость!!!
    else
        real_sort(stack_a, stack_b);                                // нужно проверять числа на одинаковость!!!
    //print_stack(*stack_a);
    //print_stack(*stack_b);
}
