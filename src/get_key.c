/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_key.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <zboub@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/07 11:47:08 by mcanal            #+#    #+#             */
/*   Updated: 2015/09/13 23:53:28 by mcanal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** get a key from stdin
*/

#include "ft_select.h"

static char		get_key(void)
{
	ssize_t	ret;
	char	buf[KEY_BUF_SIZE + 1];

	if ((ret = read(STDIN_FILENO, buf, KEY_BUF_SIZE)) < 0)
		return (FALSE);
	if (ret == 1 && *buf > 0)
		return (*buf);
	else if (*buf == 27 && *(buf + 1) == 91)
	{
		if (ret == 3)
			return (*(buf + 2) - 64);
		else if (ret == 4 && *(buf + 2) == 51 && *(buf + 3) == 126)
			return (K_DEL);
	}
	return (FALSE);
}

static void		remove_entry(void)
{
	t_lst	*to_del;

	to_del = g_env->current;
	if (ft_lisfirst(&to_del))
		g_env->first = to_del->next ? to_del->next : NULL;
	if (ft_lislast(&to_del))
		g_env->last = to_del->prev ? to_del->prev : NULL;
	if (to_del->next)
		g_env->current = to_del->next;
	else if (to_del->prev)
		g_env->current = to_del->prev;
	else
	{
		restore_term();
		ft_lclean(&g_env->first);
		exit(EXIT_SUCCESS);
	}
	ft_ldellink(to_del);
	ft_lfree(&to_del);
	print_list();
	move_cursor(42);
}

void			key_loop(void)
{
	char	key;

	move_cursor(K_START);
	while ((key = get_key()) != K_ESC)
	{
		if (!key)
			continue ;
		else if (key >= K_UP && key <= K_START)
			move_cursor(key);
		else if (key == K_DEL || key == K_BACKSPACE)
			remove_entry();
		else if (key == K_SPACE)
		{
			g_env->current->is_selected = g_env->current->is_selected ? \
				FALSE : TRUE;
			move_cursor(K_RIGHT);
		}
		else if (key == K_RETURN)
		{
			restore_term();
			print_selection();
			ft_lclean(&g_env->first);
			exit(EXIT_SUCCESS);
		}
	}
}
