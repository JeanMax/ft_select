/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <zboub@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/10 10:01:19 by mcanal            #+#    #+#             */
/*   Updated: 2015/09/12 19:17:32 by mcanal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** moving cursor around
*/

#include "ft_select.h"

static void		get_coord(char key, int *x_y)
{
	if (key == K_RIGHT)
		move_right(x_y);
	else if (key == K_LEFT)
		move_left(x_y);
	else if (key == K_UP)
		move_up(x_y);
	else if (key == K_DOWN)
		move_down(x_y);
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
