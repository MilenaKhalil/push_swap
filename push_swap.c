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
    if (a->content == ne->content
            || a->content == nene->content
            || ne->content == nene->content)
        bad_exit(stack_a, "Numbers are not unique!!!\n");        // лучше потом подключить сюда мусор!!!
    if (a->content > ne->content && a->content > nene->content)
        rotate(stack_a, 0, "ra\n");
    else if (ne->content > a->content && ne->content > nene->content)
        rotate(stack_a, 1, "rra\n");
    if ((*stack_a)->content > (*stack_a)->next->content)
        swap(stack_a, "sa\n");
}

void    sort_stack(t_list **stack_a, t_list **stack_b)           // лучше передавать сюда мусор!!!
{
    int length;

    (void) stack_b;
    length = ft_lstsize(*stack_a);
    if (length == 2)
        swap(stack_a, "sa\n");
    else if (length == 3)
        sort_three(stack_a);
/*    else if (lenght < 10)
        sort_some(&stack_a, &stack_b);
    else
        real_sort(&stack_a, &stack_b);*/
}
