/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <zboub@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/10 10:01:19 by mcanal            #+#    #+#             */
/*   Updated: 2015/09/11 20:51:35 by mcanal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** moving cursor around
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

static void		get_coord(char key, int *x_y)
{
	if (key == K_RIGHT)
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
	else if (key == K_LEFT)
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
	else if (key == K_UP)
	{
		x_y[0] = g_env->current->x;
		if (g_env->current->y)
			x_y[1] = g_env->current->y - 1;
		else
			x_y[1] = get_bottom(g_env->current);
		g_env->current = ft_lfind(&g_env->first, x_y[0], x_y[1]);
	}
	else if (key == K_DOWN)
	{
		x_y[0] = g_env->current->x;
		if (get_bottom(g_env->current) != g_env->current->y)
			x_y[1] = g_env->current->y + 1;
		else
			x_y[1] = 0;
		g_env->current = ft_lfind(&g_env->first, x_y[0], x_y[1]);
	}
	else if (key == K_END)
	{
		x_y[0] = g_env->last->x;
		x_y[1] = g_env->last->y;
		g_env->current = g_env->last;
	}
	else if (key == K_START)
	{
		x_y[0] = 0;
		x_y[1] = 0;
		g_env->current = g_env->first;
	}
	else
	{
		x_y[0] = g_env->current->x;
		x_y[1] = g_env->current->y;
	}
}

void			move_cursor(char key)
{
	int	x_y[2];

	get_coord(key, x_y);
	print_list();
	if (tputs(tgoto(tgetstr("cm", NULL), x_y[0], x_y[1]), \
			  0, tputs_output) == ERR)
		error(TPUTS, "cm");
}
