/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <zboub@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/12 18:47:46 by mcanal            #+#    #+#             */
/*   Updated: 2015/09/12 18:52:09 by mcanal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** clearly, move.c wasn't enough
*/

#include "ft_select.h"

static int		get_bottom(t_lst *link)
{
	int	x;
	int	y;

	x = link->x;
	while (link)
	{
		if (x == link->x)
			y = link->y;
		link = link->next;
	}
	return (y);
}

void			move_right(int *x_y)
{
	if (g_env->current->next)
	{
		x_y[0] = g_env->current->next->x;
		x_y[1] = g_env->current->next->y;
		g_env->current = g_env->current->next;
	}
	else
	{
		x_y[0] = 0;
		x_y[1] = 0;
		g_env->current = g_env->first;
	}
}

void			move_left(int *x_y)
{
	if (g_env->current->prev)
	{
		x_y[0] = g_env->current->prev->x;
		x_y[1] = g_env->current->prev->y;
		g_env->current = g_env->current->prev;
	}
	else
	{
		x_y[0] = g_env->last->x;
		x_y[1] = g_env->last->y;
		g_env->current = g_env->last;
	}
}

void			move_up(int *x_y)
{
	x_y[0] = g_env->current->x;
	if (g_env->current->y)
		x_y[1] = g_env->current->y - 1;
	else
		x_y[1] = get_bottom(g_env->current);
	g_env->current = ft_lfind(&g_env->first, x_y[0], x_y[1]);
}

void			move_down(int *x_y)
{
	x_y[0] = g_env->current->x;
	if (get_bottom(g_env->current) != g_env->current->y)
		x_y[1] = g_env->current->y + 1;
	else
		x_y[1] = 0;
	g_env->current = ft_lfind(&g_env->first, x_y[0], x_y[1]);
}
