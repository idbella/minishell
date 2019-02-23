/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sid-bell <sid-bell@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 00:33:37 by sid-bell          #+#    #+#             */
/*   Updated: 2019/02/23 09:02:09 by sid-bell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_changedir(char *dir, t_params *params)
{
	char *old;

	old = ft_get_env_key("PWD", params->env);
	if (access(dir, X_OK))
	{
		ft_putendl_fd("Permission denied", 2);
		return ;
	}
	if (chdir(dir))
	{
		ft_putendl(dir);
		ft_putendl("Unknown error");
		return ;
	}
	else
	{
		ft_setenv("OLDPWD", old, params);
		ft_setenv("PWD", dir, params);
	}
	free(old);
}

void	ft_helper(char *dir, t_stat *stat, t_params *params)
{
	if (S_ISDIR(stat->st_mode))
	{
		ft_changedir(dir, params);
	}
	else
	{
		ft_putstr(dir);
		ft_putendl(": Not a directory.");
	}
}

void	ft_cd(char *location, t_params *params)
{
	char	*dir;
	t_stat	*stat;

	if (location && !ft_strcmp(location, "-"))
		dir = ft_get_env_key("OLDPWD", params->env);
	else
		dir = location;
	if ((stat = ft_exist(dir)))
	{
		ft_helper(dir, stat, params);
		free(stat);
	}
	else
	{
		ft_putstr(dir);
		ft_putendl(": No such file or directory");
	}
}
