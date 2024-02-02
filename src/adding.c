/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adding.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzelouan <mzelouan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 01:25:54 by mzelouan          #+#    #+#             */
/*   Updated: 2024/02/02 01:25:55 by mzelouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int price_for_rarb(stack * target, stack *to_push)
{
	int price;

	price = target->index;
	if (price < to_push->index)
		price = to_push->index;
	return (price);
}

int price_for_rrarrb(stack *a, stack *b, stack * target, stack *to_push)
{
	int price;

	price = 0;
	if (target->index)
		price = ft_stack_size(b) - target->index;
	if (price < (ft_stack_size(a) - to_push->index) && to_push->index)
		price = ft_stack_size(a) - to_push->index;
	return (price);
}

int price_for_rrarb(stack *a, stack * target, stack *to_push)
{
	int price;

	price = 0;
	if (to_push->index)
		price = ft_stack_size(a) - to_push->index;
	price += target->index;
	return (price);
}

int price_for_rarrb(stack *b, stack * target, stack *to_push)
{
	int price;

	price = 0;
	if (target->index)
		price = ft_stack_size(b) - target->index;
	price += to_push->index;
	return (price);
}
