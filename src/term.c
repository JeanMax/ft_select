/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <zboub@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/10 09:38:09 by mcanal            #+#    #+#             */
/*   Updated: 2015/09/11 21:01:05 by mcanal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** init/restore term config, get term size, tputs output util
*/

#include "ft_select.h"

int				tputs_output(int i)
{
	return ((int)write(1, &i, 1));
}

void			get_term_size(void)
{
	ioctl(0, TIOCGWINSZ, g_env->ws);
}

void			init_term(void)
{
	char	term_buf[2048];

	if (!isatty(STDIN_FILENO))
		error(ISATTY, NULL);
	if (tgetent(term_buf, getenv("TERM")) == ERR)
		error(TERM, NULL);
	if (tcgetattr(STDIN_FILENO, g_env->term))
		error(GETATTR, NULL);
	g_env->term->c_lflag &= (unsigned int)~(ICANON);
	g_env->term->c_lflag &= (unsigned int)~(ECHO);
	g_env->term->c_cc[VTIME] = 0;
	g_env->term->c_cc[VMIN] = 1;
	if (tcsetattr(STDIN_FILENO, TCSADRAIN, g_env->term))
		error(SETATTR, NULL);
	TERM_SCREEN_SAVE;
	if (tputs(tgetstr("cl", NULL), 0, tputs_output) == ERR)
		error(TPUTS, "cl");
}

void			restore_term(void)
{
	g_env->term->c_lflag |= ICANON;
	g_env->term->c_lflag |= ECHO;
	if (tcsetattr(STDIN_FILENO, 0, g_env->term))
		error(SETATTR, NULL);
	TERM_SCREEN_RESTORE;
}
