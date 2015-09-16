/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <mcanal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/16 16:41:00 by mcanal            #+#    #+#             */
/*   Updated: 2015/09/16 17:10:43 by mcanal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void		color(t_lst *tmp)
{
	if (ft_strstr(tmp->name, ".c"))
		TERM_FG_COLOR_RED;
	else if (ft_strstr(tmp->name, ".o"))
		TERM_FG_COLOR_GREEN;
	else if (ft_strstr(tmp->name, ".d"))
		TERM_FG_COLOR_YELLOW;
	else if (ft_strstr(tmp->name, ".h"))
		TERM_FG_COLOR_MAGENTA;
	else
		TERM_FG_COLOR_CYAN;
}
