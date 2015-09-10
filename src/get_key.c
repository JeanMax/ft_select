/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_key.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <zboub@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/07 11:47:08 by mcanal            #+#    #+#             */
/*   Updated: 2015/09/10 20:25:14 by mcanal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** get a key from stdin
*/

#include "ft_select.h"

extern t_env	*g_env;

static char		get_key(void)
{
	ssize_t	ret;
	char	buf[KEY_BUF_SIZE + 1]; //TODO: give it an &char instead
	
	if ((ret = read(STDIN_FILENO, buf, KEY_BUF_SIZE)) < 0)
		return (FALSE);
	if (ret == 1 && *buf > 0) //this is a simple ascii character!
		return (*buf);
	else if (*buf == 27 && *(buf + 1) == 91) //this is an arrow!
	{
		if (ret == 3)
			return (*(buf + 2) - 64); // 64 so it match enum
		else if (ret == 4 && *(buf + 2) == 51 && *(buf + 3) == 126)//this is del
			return (K_DEL);
	}
	return (FALSE);
/*		
	ft_debugnbr("read_return", ret); //debug
	int i = 0;
	buf[ret] = 0;
	while (i < KEY_BUF_SIZE && buf[i])
	{
		ft_putnbr(buf[i]);
		ft_putstr(" = ");
		ft_putchar(buf[i]);
		ft_putstr(" | ");
		i++;
	}
	ft_putchar('\n');
	return (FALSE);
*/
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
		exit(EXIT_SUCCESS);
	}
	ft_ldellink(to_del);
	ft_lfree(&to_del);
	print_list(); //just to recalculate coords...
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
			g_env->current->is_selected = g_env->current->is_selected ? FALSE : TRUE;
			move_cursor(K_RIGHT);
		}
		else if (key == K_RETURN)
		{
			restore_term();
			print_selection();
			exit(EXIT_SUCCESS);
		}
		else
			ft_debugnbr("key", key); //debug
	}
}
