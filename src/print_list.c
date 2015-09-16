/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <zboub@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/10 09:42:51 by mcanal            #+#    #+#             */
/*   Updated: 2015/09/16 18:51:27 by mcanal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** print selected list on stdout
*/

#include "ft_select.h"

void			print_selection(void)
{
	t_lst	*tmp;

	tmp = g_env->first;
	while (tmp)
	{
		if (tmp->is_selected)
		{
			ft_putstr(tmp->name);
			ft_putchar(' ');
		}
		tmp = tmp->next;
	}
	ft_putchar('\n');
}

static size_t	longest_arg(t_lst **first)
{
	t_lst	*tmp;
	size_t	longest;

	tmp = *first;
	longest = 0;
	while (tmp)
	{
		if (tmp->len > longest)
			longest = tmp->len;
		tmp = tmp->next;
	}
	return (longest);
}

static void		print_name(t_lst *tmp, int x, int y)
{
	COLOR_TEXT ? color(tmp) : (void)0;
	if (tmp == g_env->current)
		if (tputs(tgetstr("us", NULL), 0, tputs_output) == ERR)
			error(TPUTS, "us");
	if (tmp->is_selected && \
		tputs(tgetstr("mr", NULL), 0, tputs_output) == ERR)
		error(TPUTS, "mr");
	ft_putstr_fd(tmp->name, STDIN_FILENO);
	if (tputs(tgetstr("me", NULL), 0, tputs_output) == ERR)
		error(TPUTS, "me");
	tmp->x = x;
	tmp->y = y;
}

static void		print_loop(size_t cols, size_t col_len, t_lst *tmp, int y)
{
	int		x;
	size_t	col_x;
	size_t	space_len;

	while (tmp)
	{
		col_x = cols;
		x = 0;
		while (col_x && tmp)
		{
			print_name(tmp, x, y);
			space_len = col_len - tmp->len + 1;
			x += tmp->len;
			col_x--;
			tmp = tmp->next;
			while (space_len && col_x && tmp)
			{
				ft_putchar_fd(' ', STDIN_FILENO);
				space_len--;
				x++;
			}
		}
		ft_putchar_fd('\n', STDIN_FILENO);
		y++;
	}
}

void			print_list(void)
{
	size_t	cols;
	size_t	col_len;

	if (tputs(tgetstr("cl", NULL), 0, tputs_output) == ERR)
		error(TPUTS, "cl");
	col_len = longest_arg(&g_env->first) + 3;
	cols = g_env->ws->ws_col / col_len;
	if (cols < 1 || \
		(size_t)ft_llen(&g_env->first) / cols > g_env->ws->ws_row - 1)
		ft_putendl_fd("Resize me :/", STDIN_FILENO);
	else
		print_loop(cols, col_len, g_env->first, 0);
}
