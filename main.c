/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sid-bell <sid-bell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 00:33:37 by sid-bell          #+#    #+#             */
/*   Updated: 2019/02/18 14:38:44 by sid-bell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		main(int argc, char **argv, char **env)
{
	char		*command;
	t_params	params;
	char		*shell;

	waiting = 0;
	params.env = NULL;
	signal(SIGINT, ft_catch);
	ft_parse_env(env, &params);
	shell = ft_strjoin(ft_pwd(), argv[0]);
	ft_setenv("SHELL", shell, &params);
	if (argc && argv)
		while (1)
		{
			ft_putstr("$> ");
			waiting = 0;
			if (get_next_line(0, &command) != -1)
				ft_getcommands(command, &params);
		}
	return (0);
}
