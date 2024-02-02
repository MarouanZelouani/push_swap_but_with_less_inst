/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzelouan <mzelouan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 02:15:39 by mzelouan          #+#    #+#             */
/*   Updated: 2024/02/02 02:17:22 by mzelouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

stack * get_min_in_stack(stack *s)
{
    stack *min;

    min = s;
    s = s->next;
    while (s != NULL)
    {
        if (s->data < min->data)
            min = s;
        s = s->next;
    }
    return min;
}

stack *get_node(stack *s, int data)
{
    stack *node;

    node = NULL;
    while (s != NULL)
    {
        if (s->data == data)
        {
            node = s;
            break;
        }
        s = s->next;
    }
    return node;
}

void a_set_node_to_push(stack *a, stack *b)
{
    stack *chosen_node;
    stack *head;

    head = a;
    chosen_node = a;
    a = a->next;
    while (a != NULL)
    {
        if (calculate_price_a(head, b, a, get_node(b, a->target)) 
        < calculate_price_a(head, b, chosen_node, get_node(b, chosen_node->target)))
            chosen_node = a;
        a = a->next;
    }
    if (chosen_node != NULL)
        chosen_node->to_push = 1;
}

void b_set_target (stack *a, stack *b)
{
    long target_index;
    stack *current;

    while (a != NULL)
    {
        target_index = LONG_MIN;
        current = b;
        while (current != NULL)
        {
            if (current->data < a->data && current->data > target_index)
                target_index = current->data;
            current = current->next;
        }
        if (target_index == LONG_MIN)
            a->target = get_max_in_stack(b)->data;
        else
            a->target = target_index;
        a = a->next;
    }
}