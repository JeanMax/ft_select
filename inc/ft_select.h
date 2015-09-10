/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <mcanal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/29 13:23:15 by mcanal            #+#    #+#             */
/*   Updated: 2015/09/10 20:06:51 by mcanal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H

/*
** DEFINE
*/
# define FT_SELECT_H

# define TERM_LINE_WRAP_ON		ft_putstr("\033[7h")
# define TERM_LINE_WRAP_OFF		ft_putstr("\033[7l")

# define TERM_SCROLL_DOWN		ft_putstr("\033D")
# define TERM_SCROLL_UP			ft_putstr("\033M")

# define TERM_SET_TAB			ft_putstr("\033H")
# define TERM_CLEAR_TAB			ft_putstr("\033[g")
# define TERM_CLEAR_ALL_TABS	ft_putstr("\033[3g")

# define TERM_CLEAR_LINE_END	ft_putstr("\033[K")
# define TERM_CLEAR_LINE_START	ft_putstr("\033[1K")
# define TERM_CLEAR_LINE		ft_putstr("\033[2K")
# define TERM_CLEAR_SCREEN_DOWN	ft_putstr("\033[J")
# define TERM_CLEAR_SCREEN_UP	ft_putstr("\033[1J")
# define TERM_CLEAR_SCREEN		ft_putstr("\033[2J")
//# define TERM_SCREEN_CLEAR		ft_putstr("\033[H\033[J")

# define TERM_SCREEN_SAVE		ft_putstr("\033[?47h") 
# define TERM_SCREEN_RESTORE	ft_putstr("\033[?47l") 

# define TERM_CURSOR_HOME		ft_putstr("\033[H")
# define TERM_CURSOR_GOTO(x, y)	ft_putstr("\033["), ft_putnbr(y), \
								ft_putchar(';'), ft_putnbr(x), ft_putchar'H')
# define TERM_CURSOR_SAVE		ft_putstr("\0337") //s? without attr
# define TERM_CURSOR_RESTORE	ft_putstr("\0338") //u? idem
# define TERM_CURSOR_UP			ft_putstr("\0331A") //add count before letter
# define TERM_CURSOR_DOWN		ft_putstr("\0331B") //idem
# define TERM_CURSOR_FW			ft_putstr("\0331C") //idem
# define TERM_CURSOR_BW			ft_putstr("\0331D") //idem

# define TERM_TEXT_RESTORE		ft_putstr("\033[0m") 

# define TERM_FONT_BOLD			ft_putstr("\033[1m")
# define TERM_FONT_DIM			ft_putstr("\033[2m")
# define TERM_FONT_UNDERSCORE	ft_putstr("\033[4m")
# define TERM_FONT_BLINK		ft_putstr("\033[5m")
# define TERM_FONT_REVERSE		ft_putstr("\033[7m") //or 5?
# define TERM_FONT_HIDDEN		ft_putstr("\033[8m")

# define TERM_FG_COLOR_BLACK	ft_putstr("\033[30m")
# define TERM_FG_COLOR_RED		ft_putstr("\033[31m")
# define TERM_FG_COLOR_GREEN	ft_putstr("\033[32m")
# define TERM_FG_COLOR_YELLOW	ft_putstr("\033[33m")
# define TERM_FG_COLOR_BLUE		ft_putstr("\033[34m")
# define TERM_FG_COLOR_MAGENTA	ft_putstr("\033[35m")
# define TERM_FG_COLOR_CYAN		ft_putstr("\033[36m")
# define TERM_FG_COLOR_WHITE	ft_putstr("\033[37m")
# define TERM_FG_COLOR_DEFAULT	ft_putstr("\033[39m")

# define TERM_BG_COLOR_BLACK	ft_putstr("\033[40m")
# define TERM_BG_COLOR_RED		ft_putstr("\033[41m")
# define TERM_BG_COLOR_GREEN	ft_putstr("\033[42m")
# define TERM_BG_COLOR_YELLOW	ft_putstr("\033[43m")
# define TERM_BG_COLOR_BLUE		ft_putstr("\033[44m")
# define TERM_BG_COLOR_MAGENTA	ft_putstr("\033[45m")
# define TERM_BG_COLOR_CYAN		ft_putstr("\033[46m")
# define TERM_BG_COLOR_WHITE	ft_putstr("\033[47m")
# define TERM_BG_COLOR_DEFAULT	ft_putstr("\033[49m")

# define KEY_BUF_SIZE 5

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
//void		sig_handl(int i); //TODO: static me?
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

#endif //FT_SELECT_H
