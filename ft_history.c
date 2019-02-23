/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_history.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sid-bell <sid-bell@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 00:33:37 by sid-bell          #+#    #+#             */
/*   Updated: 2019/02/20 02:59:41 by sid-bell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_history(t_list *histoy)
{
	int i;

	i = 0;
	histoy = ft_lstrev(histoy);
	while (histoy)
	{
		ft_putchar('\t');
		ft_putnbr(i);
		ft_putstr("  ");
		ft_putendl((char *)histoy->content);
		histoy = histoy->next;
		i++;
	}
	histoy = ft_lstrev(histoy);
}

void	ft_addhistory(char *str, t_list **history)
{
	t_list *new;

	new = ft_lstnew(NULL, 0);
	new->content = ft_strdup(str);
	ft_lstadd(history, new);
}
