/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_signal.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <zboub@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/27 04:34:21 by mcanal            #+#    #+#             */
/*   Updated: 2015/09/10 20:06:19 by mcanal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** this is the place to handle signals of course!
*/

#include "ft_select.h"

extern t_env	*g_env;

static void		sig_tstp(int i)
{
	(void)i;
}

static void		sig_cont(int i)
{
	(void)i;
}

static void		sig_handl(int i)
{
	if (i == SIGBUS)
		error(BUS, NULL);
	else if (i == SIGSEGV)
		error(SEG, NULL);
	else if (i == SIGFPE)
		error (FPE, NULL);
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
//	else if (i == 29) //SIGINFO
		
}

void			sig_init(void)
{
	signal(SIGINT, sig_handl);
	signal(SIGWINCH, sig_handl);
	signal(SIGFPE, sig_handl);
//	signal(29, sig_handl);
	signal(SIGSEGV, sig_handl);
	signal(SIGBUS, sig_handl);
	signal(SIGQUIT, sig_handl);
	signal(SIGTSTP, sig_tstp);
	signal(SIGCONT, sig_cont);
}
