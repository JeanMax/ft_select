/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lnew.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <mcanal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/09 22:07:36 by mcanal            #+#    #+#             */
/*   Updated: 2015/09/10 12:04:43 by mcanal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Alloue (avec malloc(3)) et retourne un maillon “frais”. Les champs content
** et content_size du nouveau maillon sont initialisés par copie des paramètr
** de la fonction. Si le paramètre content est nul, le champs content es
** initialisé à NULL et le champs content_size est initialisé à 0 que
** la valeur du paramètre content_size. Le champ next est initialisé à N.
** Si l’allocation échoue, la fonction renvoie NULL
*/

#include "libft.h"
#include <stdlib.h>

t_lst	*ft_lnew(char *name)
{
	t_lst	*new;

	if (!(new = malloc(sizeof(t_lst))))
		return (NULL);
	if (name)
	{
		if (!(new->name = ft_strdup(name)))
			return (NULL);
	}
	else
		new->name = NULL;
	new->len = ft_strlen(name);
	new->x = 0;
	new->y = 0;
	new->is_selected = FALSE;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}
