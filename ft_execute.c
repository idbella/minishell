/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sid-bell <sid-bell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 00:33:37 by sid-bell          #+#    #+#             */
/*   Updated: 2019/02/17 17:38:50 by sid-bell         ###   ########.fr       */
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
		pid = fork();
		if (!pid)
		{
			env = ft_get_env(params->env);
			r_val = execve(file, params->args, env);
			if (r_val == -1)
				ft_putendl("Error");
		}
		else
			wait4(pid, NULL, 0, NULL);
	}
	else
	{
		ft_putstr("Minishell: command not found: ");
		ft_putendl(cmd);
	}
}
