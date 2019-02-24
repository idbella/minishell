/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_built_in.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sid-bell <sid-bell@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 00:33:37 by sid-bell          #+#    #+#             */
/*   Updated: 2019/02/24 00:28:56 by sid-bell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_built_in(char *name, t_params *params, char **command)
{
	if (!ft_strcmp(name, "cd"))
		ft_cd(params->args[1], params);
	if (!ft_strcmp(name, "echo"))
		ft_echo(params);
	if (!ft_strcmp(name, "env"))
		ft_env(params->env);
	if (!ft_strcmp(name, "setenv"))
		ft_setenv(params->args[1], params->args[2], params);
	if (!ft_strcmp(name, "unsetenv"))
		ft_unsetenv(params->args[1], params);
	else if (!ft_strcmp(name, "exit"))
	{
		ft_atexit(params);
		free(*command);
		exit(0);
	}
	else if (!ft_strcmp(name, "history"))
		ft_history(params->history);
	else if (!ft_strcmp(name, "set_preview"))
		params->preview_mode = 1;
	else if (!ft_strcmp(name, "unset_preview"))
		params->preview_mode = 0;
}
