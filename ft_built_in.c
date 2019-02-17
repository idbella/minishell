/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_built_in.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sid-bell <sid-bell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 00:33:37 by sid-bell          #+#    #+#             */
/*   Updated: 2019/02/17 06:52:57 by sid-bell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int ft_isbuilt_in(char *name)
{
	if (!ft_strcmp(name, "cd"))
		return (1);
	if (!ft_strcmp(name, "echo"))
		return (1);
	if (!ft_strcmp(name, "exit"))
		return (1);
	if (!ft_strcmp(name, "env"))
		return (1);
	if (!ft_strcmp(name, "setenv"))
		return (1);
	if (!ft_strcmp(name, "unsetenv"))
		return (1);
	return (0);
}

void    ft_built_in(char *name, t_params *params)
{
	if (!ft_strcmp(name, "cd"))
		ft_cd(params->args[1], params);
	if (!ft_strcmp(name, "echo"))
		ft_echo(params);
	if (!ft_strcmp(name, "env"))
		ft_env(params->env);
	if (!ft_strcmp(name, "setenv"))
		ft_setenv(params->args[1], params->args[2], params);
	else if (!ft_strcmp(name, "exit"))
		exit(0);
}