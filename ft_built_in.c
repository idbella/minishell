/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_built_in.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sid-bell <sid-bell@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 00:33:37 by sid-bell          #+#    #+#             */
/*   Updated: 2019/02/19 05:18:51 by sid-bell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_built_in(char *name, t_params *params)
{
	if (!ft_strcmp(name, "cd"))
		ft_cd(params->args[1], params);
	if (!ft_strcmp(name, "echo"))
		ft_echo(params);
	if (!ft_strcmp(name, "env"))
		ft_env(params->env);
	if (!ft_strcmp(name, "setenv"))
		ft_setenv(params->args[1], params->args[2], params);
	if (!ft_strcmp(name, "unsetenv"))
		ft_unsetenv(params->args[1], params);
	else if (!ft_strcmp(name, "exit"))
		exit(0);
}
