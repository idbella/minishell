/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sid-bell <sid-bell@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 00:33:37 by sid-bell          #+#    #+#             */
/*   Updated: 2019/02/24 01:07:49 by sid-bell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_helper(char *cmd, char *file, t_params *params)
{
	char	**env;
	int		pid;

	if (access(file, X_OK))
	{
		ft_putstr_fd(cmd, 2);
		ft_putstr_fd(": ", 2);
		ft_putendl_fd("Permission denied", 2);
		return ;
	}
	pid = fork();
	if (!pid)
	{
		env = ft_get_env(params->env);
		if (execve(file, params->args, env) == -1)
			ft_putendl_fd("Permission denied", 2);
		exit(0);
	}
	else
	{
		g_waiting = 1;
		wait(NULL);
	}
}

void		ft_execute(char *cmd, t_params *params)
{
	char	*file;

	if ((file = ft_find_file(cmd, params->env)))
	{
		ft_helper(cmd, file, params);
		free(file);
	}
	else
	{
		ft_putstr("Minishell: command not found: ");
		ft_putendl(cmd);
	}
}
