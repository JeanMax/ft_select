/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_signal.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <zboub@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/27 04:34:21 by mcanal            #+#    #+#             */
/*   Updated: 2015/09/11 21:00:12 by mcanal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** this is the place to handle signals of course!
*/

#include "ft_select.h"

static void		sig_tstp(int i)
{
	t_char	s[2];

	(void)i;
	*s = g_env->term->c_cc[VSUSP];
	*(s + 1) = 0;
	restore_term();
	signal(SIGTSTP, SIG_DFL);
	ioctl(0, TIOCSTI, s);
}

static void		sig_cont(int i)
{
	(void)i;
	signal(SIGTSTP, sig_tstp);
	init_term();
	move_cursor(42);
}

static void		sig_handl(int i)
{
	if (i == SIGBUS)
		error(BUS, NULL);
	else if (i == SIGSEGV)
		error(SEG, NULL);
	else if (i == SIGFPE)
		error(FPE, NULL);
	else if (i == SIGINT || i == SIGQUIT)
	{
		restore_term();
		exit(EXIT_SUCCESS);
	}
	else if (i == SIGWINCH)
	{
		get_term_size();
		print_list();
	}
}

void			sig_init(void)
{
	signal(SIGINT, sig_handl);
	signal(SIGWINCH, sig_handl);
	signal(SIGFPE, sig_handl);
	signal(SIGSEGV, sig_handl);
	signal(SIGBUS, sig_handl);
	signal(SIGQUIT, sig_handl);
	signal(SIGTSTP, sig_tstp);
	signal(SIGCONT, sig_cont);
}
