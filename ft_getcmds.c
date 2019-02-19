/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getcmds.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sid-bell <sid-bell@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 00:33:37 by sid-bell          #+#    #+#             */
/*   Updated: 2019/02/19 05:06:12 by sid-bell         ###   ########.fr       */
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

void		ft_getcommands(char *str, t_params *params)
{
	int		i;
	int		start;
	int		qoute;
	int		dqoute;
	char	*s;

	i = 0;
	qoute = 0;
	dqoute = 0;
	start = 0;
	if (!ft_isvalid(str))
		return ;
	while (str[i])
	{
		if (!qoute && !dqoute && str[i] == ';')
		{
			s = ft_strsub(str, start, i - start);
			ft_parse(s, params);
			start = i + 1;
		}
		else if (!dqoute && str[i] == '\'')
			qoute = !qoute;
		else if (!qoute && str[i] == '\"')
			dqoute = !dqoute;
		if (!str[i + 1] && str[i] != ';')
		{
			s = ft_strsub(str, start, i - start + 1);
			ft_parse(s, params);
		}
		i++;
	}
}
