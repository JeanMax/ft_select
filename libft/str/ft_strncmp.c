/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <mcanal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 15:44:28 by mcanal            #+#    #+#             */
/*   Updated: 2015/07/22 01:08:06 by mcanal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The  strncmp() function  is similar to strcmp(), except it compares the
** only first (at most) n bytes of s1 and s2.
*/

#include "libft.h"

int ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if (!n)
		return (0);
	while (n && *s1 && *s2 && *s1 == *s2)
		s1++, s2++, n--;
	return (n ? (t_char)*s1 - (t_char)*s2 : \
				(t_char)*(s1 - 1) - (t_char)*(s2 - 1));
}
