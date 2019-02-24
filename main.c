/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sid-bell <sid-bell@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 04:22:06 by sid-bell          #+#    #+#             */
/*   Updated: 2019/02/24 05:11:14 by sid-bell         ###   ########.fr       */
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
			g_waiting_child = 0;
			if ((command = ft_getline(&params)))
				ft_getcommands(command, &params);
			free(command);
			g_line = NULL;
		}
	ft_atexit(&params);
	return (0);
}
