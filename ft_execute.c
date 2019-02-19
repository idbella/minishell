/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sid-bell <sid-bell@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 00:33:37 by sid-bell          #+#    #+#             */
/*   Updated: 2019/02/19 05:43:20 by sid-bell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_execute(char *cmd, t_params *params)
{
	int		pid;
	int		r_val;
	char	*file;
	char	**env;

	if ((file = ft_find_file(cmd, params->env)))
	{
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
			r_val = execve(file, params->args, env);
			if (r_val == -1)
				printf("error %s\n", ft_strerror(errno));
		}
		else
		{
			g_waiting = 1;
			wait4(pid, NULL, 0, NULL);
		}
	}
	else
	{
		ft_putstr("Minishell: command not found: ");
		ft_putendl(cmd);
	}
}
