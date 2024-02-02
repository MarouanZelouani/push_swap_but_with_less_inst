/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_cases_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzelouan <mzelouan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 00:52:40 by mzelouan          #+#    #+#             */
/*   Updated: 2024/02/02 02:02:36 by mzelouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void case_1_a (stack *to_push, stack *target, stack **a, stack **b) // rrarrb
{
    while (to_push->index != 0 && target->index != 0)
    {
        reverse_rotate_ab(a, b, 1);
        set_index_to_node(*a);
        set_index_to_node(*b);
    }
    while (target->index != 0)
    {
        reverse_rotate_b(b, 1);
        set_index_to_node(*b);
    }
    while (to_push->index != 0)
    {
        reverse_rotate_a(a, 1);
        set_index_to_node(*a);
    }
}

void case_4_a (stack *to_push, stack *target, stack **a, stack **b) // rarb
{
    while (to_push->index != 0 && target->index != 0)
    {
        rotate_ab(a, b, 1);
        set_index_to_node(*a);
        set_index_to_node(*b);
    }
    while (target->index != 0)
    {
        rotate_b(b, 1);
        set_index_to_node(*b);
    }
    while (to_push->index != 0)
    {
        rotate_a(a, 1);
        set_index_to_node(*a);
    }
}

void case_2_a (stack *to_push, stack *target, stack **a, stack **b) // rarrb
{
    while (to_push->index != 0)
    {
        rotate_a(a, 1);
        set_index_to_node(*a);
    }
    while (target->index != 0)
    {
        reverse_rotate_b(b, 1);
        set_index_to_node(*b);
    }
}

void case_3_a (stack *to_push, stack *target, stack **a, stack **b) // rrarb
{
    while (to_push->index != 0)
    {
        reverse_rotate_a(a, 1);
        set_index_to_node(*a);
    }
    while (target->index != 0)
    {
        rotate_b(b, 1);
        set_index_to_node(*b);
    }
}