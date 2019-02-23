/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_joinargs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sid-bell <sid-bell@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 00:33:37 by sid-bell          #+#    #+#             */
/*   Updated: 2019/02/23 05:31:59 by sid-bell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ft_helper1(char *str, int r)
{
	while (r >= 0)
	{
		if (str[r] == '\"' || str[r] == '\'' || ft_isspace(str[r]))
			break ;
		r--;
	}
	return (r);
}

static void	ft_helper2(char c, t_bool *qoute)
{
	if (c == '\'')
		qoute[0] = !qoute[0];
	else if (c == '\"')
		qoute[1] = !qoute[1];
}

char		*ft_joinargs(char **str, char *result)
{
	int		i[2];
	t_bool	qoute[2];
	char	c;

	qoute[0] = 0;
	qoute[1] = 0;
	i[0] = -1;
	result = ft_strdup(*str);
	free(*str);
	while (result[++i[0]])
	{
		if (!qoute[0] && !qoute[1] && !ft_isspace(result[i[0]]) &&
			(result[i[0] + 1] == '\"' || result[i[0] + 1] == '\''))
		{
			i[1] = ft_helper1(result, i[0]);
			c = result[i[0] + 1];
			result = ft_delchar(&result, i[0] + 1);
			result = ft_insertchar(&result, c, i[1] + 1);
			qoute[0] = c == '\'' ? 1 : 0;
			qoute[1] = c == '\"' ? 1 : 0;
			i[0]++;
		}
		ft_helper2(result[i[0]], qoute);
	}
	return (result);
}
