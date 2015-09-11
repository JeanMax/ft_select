/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <mcanal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/29 13:23:15 by mcanal            #+#    #+#             */
/*   Updated: 2015/09/11 20:39:12 by mcanal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H

/*
** DEFINE
*/
# define FT_SELECT_H
# define KEY_BUF_SIZE			5
# define TERM_SCREEN_SAVE		ft_putstr("\033[?47h") 
# define TERM_SCREEN_RESTORE	ft_putstr("\033[?47l") 

/*
** INCLUDE
*/
# include "libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <signal.h>
# include <curses.h>
# include <term.h>
# include <termios.h>
# include <fcntl.h>
# include <sys/ioctl.h>
# include <sys/types.h>
# include <sys/stat.h>


/*
** ENUM
*/
enum	e_error
{
	MALLOC,
	BUS,
	SEG,
	FPE,
	TERM,
	GETATTR,
	SETATTR,
	ISATTY,
	LIST,
	TPUTS
};

enum	e_key
{
	K_UP = 1,
	K_DOWN = 2,
	K_RIGHT = 3,
	K_LEFT = 4,
	K_END = 6,
	K_START = 8,
	K_DEL = 9,
	K_RETURN = 10,
	K_ESC = 27,
	K_SPACE = 32,
	K_BACKSPACE = 127
};

/*
** STRUCT && TYPEDEF
*/
typedef struct s_env	t_env;
struct		s_env
{
	t_lst			*first;
	t_lst			*last;
	t_lst			*current;
	struct termios	*term;
	struct winsize	*ws;
};


/*
** GLOBAL
*/
extern t_env			*g_env;

/*
** PROTOTYPES
**
**  -get_key.c
*/
void		key_loop(void);

/*
**  -error.c
*/
void		error(char error, char *msg);

/*
**  -signal.c
*/
void		sig_init(void);

/*
**  -term.c
*/
void		init_term(void);
void		restore_term(void);
void		get_term_size(void);
int			tputs_output(int i);

/*
**  -print_list.c
*/
void		print_list(void);
void		print_selection(void);

/*
**  -move.c
*/
void		move_cursor(char key);

#endif
