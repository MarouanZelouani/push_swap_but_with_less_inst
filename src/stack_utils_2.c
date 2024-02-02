/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzelouan <mzelouan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 08:58:24 by mzelouan          #+#    #+#             */
/*   Updated: 2024/02/02 02:17:36 by mzelouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void set_target(stack *a, stack *b)
{
    long target_index;
    stack *current;

    while (b != NULL)
    {
        target_index = LONG_MAX;
        current = a;
        while (current != NULL)
        {
            if (current->data > b->data && current->data < target_index)
                target_index = current->data;
            current = current->next;
        }
        if (target_index == LONG_MAX)
            b->target = get_min_in_stack(a)->data;
        else
            b->target = target_index;
        b = b->next;
    }
}

int calculate_price(stack *a, stack *b, stack *chosen_node, stack *target_node)
{
    int total_price;

    total_price = price_for_rarb_a(target_node, chosen_node);
    if (total_price > price_for_rarrb_a(a, target_node, chosen_node))
        total_price = price_for_rarrb_a(b, target_node, chosen_node);
    if (total_price > price_for_rrarb_a(a, target_node, chosen_node))
        total_price = price_for_rrarb_a(a, target_node, chosen_node);
    if (total_price > price_for_rrarrb_a(a, b, target_node, chosen_node))
        total_price = price_for_rrarrb_a(a, b, target_node, chosen_node);
    return total_price;
}

int calculate_price_a(stack *a, stack *b, stack *chosen_node, stack *target_node)
{  
    int total_price;

    total_price = price_for_rarb(target_node, chosen_node);
    if (total_price > price_for_rarrb(a, target_node, chosen_node))
        total_price = price_for_rarrb(b, target_node, chosen_node);
    if (total_price > price_for_rrarb(a, target_node, chosen_node))
        total_price = price_for_rrarb(a, target_node, chosen_node);
    if (total_price > price_for_rrarrb(a, b, target_node, chosen_node))
        total_price = price_for_rrarrb(a, b, target_node, chosen_node);
    return total_price;
}

void set_node_to_push(stack *a, stack *b)
{
    stack *chosen_node;
    stack *head;

    head = b;
    chosen_node = NULL;
    while (b != NULL)
    {
        if (chosen_node == NULL || 
        calculate_price(a, head, b, get_node(a, b->target)) 
        < calculate_price(a, head, chosen_node, get_node(a, chosen_node->target)))
            chosen_node = b;
        b = b->next;
    }
    if (chosen_node != NULL)
        chosen_node->to_push = 1;
}