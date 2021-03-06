/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_history.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sid-bell <sid-bell@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 00:33:37 by sid-bell          #+#    #+#             */
/*   Updated: 2019/02/24 00:28:36 by sid-bell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_history(t_list *list)
{
	if (list->next)
		ft_history(list->next);
	ft_putchar('\t');
	ft_putendl((char *)list->content);
}

void	ft_addhistory(char *str, t_list **history)
{
	t_list *new;

	new = ft_lstnew(NULL, 0);
	new->content = ft_strdup(str);
	ft_lstadd(history, new);
}
