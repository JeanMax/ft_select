/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <zboub@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/04 12:00:08 by mcanal            #+#    #+#             */
/*   Updated: 2015/09/13 23:53:46 by mcanal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** main!
*/

#include "ft_select.h"

t_env			*g_env;

static void		fill_list(char **av)
{
	g_env->first = NULL;
	while (*av)
	{
		if (!g_env->first)
			g_env->first = ft_lnew(*av);
		else
			ft_laddlast(&g_env->first, ft_lnew(*av));
		av++;
	}
	g_env->current = g_env->first;
	g_env->last = ft_llast(&g_env->first);
	if (!g_env->first)
		error(LIST, NULL);
}

int				main(int ac, char **av)
{
	t_env			e;
	struct termios	term;
	struct winsize	ws;

	if (ac == 1)
		return (EXIT_SUCCESS);
	g_env = &e;
	g_env->ws = &ws;
	g_env->term = &term;
	sig_init();
	init_term();
	get_term_size();
	fill_list(++av);
	key_loop();
	restore_term();
	ft_lclean(&g_env->first);
	return (EXIT_SUCCESS);
}
