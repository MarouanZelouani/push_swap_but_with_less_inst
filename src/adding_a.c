/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adding_a.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzelouan <mzelouan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 01:25:57 by mzelouan          #+#    #+#             */
/*   Updated: 2024/02/02 01:25:58 by mzelouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int price_for_rarb_a(stack * target, stack *to_push)
{
	int price;

	price = target->index;
	if (price < to_push->index)
		price = to_push->index;
	return (price);
}

int price_for_rrarrb_a(stack *a, stack *b, stack * target, stack *to_push)
{
	int price;

	price = 0;
	if (target->index)
		price = ft_stack_size(a) - target->index;
	if ((price < (ft_stack_size(b) - to_push->index)) && to_push->index)
		price = ft_stack_size(b) - to_push->index;
	return (price);
}

int price_for_rrarb_a(stack *a, stack * target, stack *to_push)
{
	int price;

	price = 0;
	if (target->index)
		price = ft_stack_size(a) - target->index;
	price += to_push->index;
	return (price);
}

int price_for_rarrb_a(stack *b, stack * target, stack *to_push)
{
	int price;

	price = 0;
	if (to_push->index)
		price = ft_stack_size(b) - to_push->index;
	price += target->index;
	return (price);
}
