/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sid-bell <sid-bell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 00:33:37 by sid-bell          #+#    #+#             */
/*   Updated: 2019/02/17 22:40:46 by sid-bell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_parse(char *command, t_params *params)
{
	char	*cmd;
	char	*str;

	str = ft_gethome(command, params);
	str = ft_joinargs(str);
	str = ft_remove_wsapces(str);
	params->args = ft_strsplit(str, -1);
	cmd = params->args[0];
	if (params->args && cmd)
	{
		if (ft_isbuilt_in(cmd))
		{
			ft_built_in(cmd, params);
		}
		else
		{
			ft_execute(cmd, params);
		}
	}
}

char    *ft_remove_wsapces(char *str)
{
	char	*new;
	char	*tmp;
	t_bool	skip;
    int     i;

	skip = 0;
	new = ft_strtrim(str);
	tmp = new;
	new = ft_strctrim(new, '\t');
	free(tmp);
	i = 0;
    while (new[i])
	{
		if (!skip && ft_isspace(new[i]))
           new[i] = -1;
		else if (new[i] == '\"')
		{
			new[i] = -1;
			skip = !skip;
		}
		i++;
	}
    return (new);
}
