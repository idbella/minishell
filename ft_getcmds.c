/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getcmds.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sid-bell <sid-bell@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 00:33:37 by sid-bell          #+#    #+#             */
/*   Updated: 2019/02/23 06:18:46 by sid-bell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ft_isvalid(char *str)
{
	int	index;
	int qoutes;
	int	dqouts;

	index = 0;
	qoutes = 0;
	dqouts = 0;
	while (str[index])
	{
		if (!(qoutes % 2) && str[index] == '\"')
			dqouts++;
		else if (!(dqouts % 2) && str[index] == '\'')
			qoutes++;
		index++;
	}
	if (dqouts % 2 || qoutes % 2)
	{
		ft_putstr_fd("Unmatched ", 2);
		ft_putchar_fd(dqouts % 2 ? '\"' : '\'', 2);
		ft_putstr_fd(".\n", 2);
		return (0);
	}
	return (1);
}

void		ft_qoutes(char c, t_bool *qoute)
{
	if (!qoute[1] && c == '\'')
		qoute[0] = !qoute[0];
	else if (!qoute[0] && c == '\"')
		qoute[1] = !qoute[1];
}

static void	ft_helper(t_params *params, char *str, int start, int len)
{
	char	*s;

	s = ft_strsub(str, start, len);
	ft_parse(s, params);
	free(s);
}

void		ft_getcommands(char *str, t_params *params)
{
	int		i;
	int		start;
	t_bool	qoute[2];

	i = -1;
	qoute[0] = 0;
	qoute[1] = 0;
	start = 0;
	ft_addhistory(str, &params->history);
	if (!ft_isvalid(str))
		return ;
	while (str[++i])
	{
		if (!qoute[0] && !qoute[1] && str[i] == ';')
		{
			ft_helper(params, str, start, i - start);
			start = i + 1;
		}
		ft_qoutes(str[i], &qoute[0]);
		if (!str[i + 1] && str[i] != ';')
			ft_helper(params, str, start, i - start + 1);
	}
}
