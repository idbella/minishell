/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sid-bell <sid-bell@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 00:33:37 by sid-bell          #+#    #+#             */
/*   Updated: 2019/02/23 06:38:34 by sid-bell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_free_args(t_params *params)
{
	char **arg;

	arg = params->args;
	while (*arg)
	{
		free(*arg);
		arg++;
	}
	free(params->args);
}

static void	ft_helper(char *command, t_params *params)
{
	char	*cmd;

	cmd = params->args[0];
	if (params->args && cmd)
	{
		if (ft_isbuilt_in(cmd))
			ft_built_in(cmd, params, &command);
		else
			ft_execute(cmd, params);
	}
}

void		ft_parse(char *command, t_params *params)
{
	char	*str;
	char	*tmp;

	str = ft_getvars(command, params);
	tmp = str;
	str = ft_gethome(str, params);
	free(tmp);
	str = ft_joinargs(&str, NULL);
	str = ft_strrev(str);
	str = ft_joinargs(&str, NULL);
	str = ft_strrev(str);
	tmp = str;
	str = ft_remove_wsapces(str);
	free(tmp);
	tmp = str;
	params->args = ft_strsplit(str, -1);
	free(str);
	ft_helper(command, params);
	ft_free_args(params);
}
