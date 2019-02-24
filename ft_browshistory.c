/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_browshistory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sid-bell <sid-bell@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 00:33:37 by sid-bell          #+#    #+#             */
/*   Updated: 2019/02/24 03:16:14 by sid-bell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_helper(t_params *params, char **str)
{
	t_list	*list;
	int		pos;

	pos = 0;
	list = params->history;
	while (list)
	{
		if (pos == params->history_pos)
		{
			free(*str);
			*str = ft_strdup((char *)list->content);
		}
		pos++;
		list = list->next;
	}
}

void		ft_browshistory(char **str, char direction, t_params *params)
{
	int		len;

	if (direction == 'A')
	{
		len = ft_lstcount(params->history);
		if (params->history && params->history_pos + 1 < len)
			params->history_pos += 1;
		else
			return ;
	}
	else
	{
		if (params->history_pos < 0)
			return ;
		params->history_pos -= 1;
		if (params->history_pos == -1)
		{
			free(*str);
			*str = ft_strnew(0);
		}
	}
	ft_helper(params, str);
}
