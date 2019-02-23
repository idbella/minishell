/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sid-bell <sid-bell@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 00:33:37 by sid-bell          #+#    #+#             */
/*   Updated: 2019/02/23 01:14:25 by sid-bell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_init(t_params *params, char **env)
{
	char		*shell;

	g_waiting = 0;
	params->preview_mode = 0;
	g_line = ft_strnew(0);
	params->env = NULL;
	params->history = NULL;
	tcgetattr(0, &params->mode);
	signal(SIGINT, ft_catch);
	ft_parse_env(env, params);
	shell = ft_get_env_key("_", params->env);
	ft_setenv("SHELL", shell, params);
	free(shell);
}

int		main(int argc, char **argv, char **env)
{
	char		*command;
	t_params	params;

	ft_init(&params, env);
	if (argc && argv)
		while (1)
		{
			ft_putstr("$> ");
			g_waiting = 0;
			if ((command = ft_getline(&params)))
				ft_getcommands(command, &params);
			free(command);
			g_line = NULL;
		}
	ft_atexit(&params);
	return (0);
}
