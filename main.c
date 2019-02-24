/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sid-bell <sid-bell@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 00:33:37 by sid-bell          #+#    #+#             */
/*   Updated: 2019/02/24 01:50:50 by sid-bell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
