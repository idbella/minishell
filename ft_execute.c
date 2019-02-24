/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sid-bell <sid-bell@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 00:33:37 by sid-bell          #+#    #+#             */
/*   Updated: 2019/02/24 08:21:10 by sid-bell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_free(char **env)
{
	int i;

	i = 0;
	if (env)
	{
		while (env[i])
		{
			free(env[i]);
			i++;
		}
		free(env);
	}
}

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
	env = ft_get_env(params->env);
	if (!pid)
	{
		if (execve(file, params->args, env) == -1)
			ft_putendl_fd("Permission denied", 2);
		exit(0);
	}
	else
	{
		g_waiting_child = 1;
		wait(NULL);
		ft_free(env);
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
