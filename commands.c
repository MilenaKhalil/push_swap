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

void    swap(t_list **stack, char *str)                     //       sa, sb
{
    t_list  *second;
    if (!(*stack) || !(*stack)->next)
        return ;
    second = (*stack)->next;
    (*stack)->next = second->next;
    second->next = (*stack);
    (*stack) = second;
    write(1, str, ft_strlen(str));
}

void    swap_swap(t_list **stack_a, t_list **stack_b, char *str) //       ss
{
    swap(stack_a, 0);
    swap(stack_b, 0);
    write(1, str, ft_strlen(str));
}

void    push(t_list **stack_a, t_list **stack_b, char *com)    //       pb, pa
{
    t_list  *second;
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
}

void    rotate(t_list **stack, int rev, char *str)            //       ra, rb, rra, rrb
{
    t_list  *last;
    t_list  *temp;
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

void    two_rot(t_list **stack_a, t_list **stack_b, char *com, char *str) //      rr, rrr
{
    int rev;

    rev = 0;
    if (ft_strlen(com) == 3)
        rev = 1;
    rotate(stack_a, rev, 0);
    rotate(stack_b, rev, 0);
    write(1, str, ft_strlen(str));
}
