/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <zboub@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/09 19:39:48 by mcanal            #+#    #+#             */
/*   Updated: 2015/09/10 19:55:51 by mcanal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** error handling
*/

#include "ft_select.h"

void		error(char e, char *msg)
{
	if (e == MALLOC)
		fail("Malloc failed with var: "), failn(msg);
	else if (e == BUS)
		failn("Bus error.");
	else if (e == SEG)
		failn("Segmentation fault.");
	else if (e == FPE)
		failn("Floating point exception.");
	else if (e == TERM)
		failn("Termcaps initialization failed.");
	else if (e == GETATTR)
		failn("tcgetattr failed.");
	else if (e == SETATTR)
		failn("tcsetattr failed.");
	else if (e == ISATTY)
		failn("This is not a tty.");
	else if (e == LIST)
		failn("Fillling list failed.");
	else if (e == TPUTS)
		fail("Tputs failed with str: "), failn(msg);
	restore_term();
	exit(EXIT_FAILURE);
}
