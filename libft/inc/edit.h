/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edit.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <mcanal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/09 03:39:14 by mcanal            #+#    #+#             */
/*   Updated: 2015/09/10 20:08:52 by mcanal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EDIT_H

# define EDIT_H

/*
** lst1 struct
*/
typedef struct s_list	t_list;
struct	s_list
{
	void	*content;
	size_t	content_size;
	t_list	*next;
};

/*
** lst2 struct
*/
typedef struct s_lst	t_lst;
struct	s_lst
{
	char	*name;
	size_t	len;
	int		x;
	int		y;
	char	is_selected;
	t_lst	*next;
	t_lst	*prev;
};

/*
** lst1
*/
void	ft_lstdelone(t_list **alst, void (*del)(void*, size_t));
t_list	*ft_lstfind(t_list **alst, void *data);
t_list	*ft_lstnew(void const *content, size_t content_size);
t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));

/*
** lst2
*/
t_lst	*ft_lnew(char *name);
t_lst	*ft_lfind(t_lst **alst, int x, int y);
void	ft_lfree(t_lst **lst);

#endif
