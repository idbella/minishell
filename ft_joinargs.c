/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_joinargs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sid-bell <sid-bell@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 00:33:37 by sid-bell          #+#    #+#             */
/*   Updated: 2019/02/19 05:23:27 by sid-bell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_joinargs(char *str)
{
	int		i;
	int		r;
	int		qoute;
	int		dqoute;
	char	c;

	qoute = 0;
	dqoute = 0;
	i = 0;
	r = 0;
	while (str[i])
	{
		if (!qoute && !dqoute && !ft_isspace(str[i]) &&
			(str[i + 1] == '\"' || str[i + 1] == '\''))
		{
			r = i;
			while (r >= 0)
			{
				if (str[r] == '\"' || str[r] == '\'' || ft_isspace(str[r]))
					break ;
				r--;
			}
			c = str[i + 1];
			str = ft_delchar(str, i + 1);
			str = ft_insertchar(str, c, r + 1);
			qoute = c == '\'' ? 1 : 0;
			dqoute = c == '\"' ? 1 : 0;
			i++;
		}
		if (str[i] == '\'')
			qoute = !qoute;
		else if (str[i] == '\"')
			dqoute = !dqoute;
		i++;
	}
	return (str);
}
