/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sid-bell <sid-bell@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 00:33:37 by sid-bell          #+#    #+#             */
/*   Updated: 2019/02/24 02:08:10 by sid-bell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_init(t_params *params, char **env)
{
	char		*shell;
	char		*pwd;

	g_waiting = 0;
	params->preview_mode = 0;
	g_line = ft_strnew(0);
	params->env = NULL;
	params->history = NULL;
	tcgetattr(0, &params->mode);
	ft_setup_terminal();
	signal(SIGINT, ft_catch);
	ft_parse_env(env, params);
	if ((shell = ft_get_env_key("_", params->env)))
		ft_setenv("SHELL", shell, params);
	if ((pwd = ft_get_env_key("PWD", params->env)))
		params->pwd = ft_strdup(pwd);
	else
	{
		pwd = ft_pwd();
		params->pwd = ft_strdup(pwd);
	}
	free(shell);
	free(pwd);
}
