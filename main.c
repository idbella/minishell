/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sid-bell <sid-bell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 00:33:37 by sid-bell          #+#    #+#             */
/*   Updated: 2019/02/17 21:21:29 by sid-bell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		main(int argc, char **argv, char **env)
{
	char		*command;
	t_params	params;

	waiting = 0;
	params.env = NULL;
	signal(SIGINT, ft_catch);
	ft_parse_env(env, &params);
	ft_setenv("var", "val", &params);
	if (argc && argv)
		while (1)
		{
			if (waiting)
				ft_putchar('\n');
			ft_putstr("$> ");
			waiting = 0;
			if (get_next_line(0, &command) != -1)
				ft_parse(command, &params);
		}
	return (0);
}
