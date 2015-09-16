/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <mcanal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/29 13:23:15 by mcanal            #+#    #+#             */
/*   Updated: 2015/09/16 17:15:20 by mcanal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H

/*
** DEFINE
*/
# define FT_SELECT_H

# define KEY_BUF_SIZE			5
# define COLOR_TEXT				TRUE

# define TERM_SCREEN_SAVE		ft_putstr_fd("\033[?1049h\033[H", STDIN_FILENO)
# define TERM_SCREEN_RESTORE	ft_putstr_fd("\033[?1049l", STDIN_FILENO)

# define TERM_FG_COLOR_BLACK	ft_putstr_fd("\033[30m", STDIN_FILENO)
# define TERM_FG_COLOR_RED		ft_putstr_fd("\033[31m", STDIN_FILENO)
# define TERM_FG_COLOR_GREEN	ft_putstr_fd("\033[32m", STDIN_FILENO)
# define TERM_FG_COLOR_YELLOW	ft_putstr_fd("\033[33m", STDIN_FILENO)
# define TERM_FG_COLOR_BLUE		ft_putstr_fd("\033[34m", STDIN_FILENO)
# define TERM_FG_COLOR_MAGENTA	ft_putstr_fd("\033[35m", STDIN_FILENO)
# define TERM_FG_COLOR_CYAN		ft_putstr_fd("\033[36m", STDIN_FILENO)
# define TERM_FG_COLOR_WHITE	ft_putstr_fd("\033[37m", STDIN_FILENO)
# define TERM_FG_COLOR_DEFAULT	ft_putstr_fd("\033[39m", STDIN_FILENO)

# define TERM_BG_COLOR_BLACK	ft_putstr_fd("\033[40m", STDIN_FILENO)
# define TERM_BG_COLOR_RED		ft_putstr_fd("\033[41m", STDIN_FILENO)
# define TERM_BG_COLOR_GREEN	ft_putstr_fd("\033[42m", STDIN_FILENO)
# define TERM_BG_COLOR_YELLOW	ft_putstr_fd("\033[43m", STDIN_FILENO)
# define TERM_BG_COLOR_BLUE		ft_putstr_fd("\033[44m", STDIN_FILENO)
# define TERM_BG_COLOR_MAGENTA	ft_putstr_fd("\033[45m", STDIN_FILENO)
# define TERM_BG_COLOR_CYAN		ft_putstr_fd("\033[46m", STDIN_FILENO)
# define TERM_BG_COLOR_WHITE	ft_putstr_fd("\033[47m", STDIN_FILENO)
# define TERM_BG_COLOR_DEFAULT	ft_putstr_fd("\033[49m", STDIN_FILENO)

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
**	-get_key.c
*/
void		key_loop(void);

/*
**	-error.c
*/
void		error(char error, char *msg);

/*
**	-signal.c
*/
void		sig_init(void);

/*
**	-term.c
*/
void		init_term(void);
void		restore_term(void);
void		get_term_size(void);
int			tputs_output(int i);

/*
**	-print_list.c
*/
void		print_list(void);
void		print_selection(void);

/*
**	-move.c
*/
void		move_cursor(char key);

/*
**	-move2.c
*/
void		move_right(int *x_y);
void		move_left(int *x_y);
void		move_up(int *x_y);
void		move_down(int *x_y);

/*
**	-color.c
*/
void		color(t_lst *tmp);

#endif
