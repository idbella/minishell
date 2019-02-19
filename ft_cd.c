/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sid-bell <sid-bell@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 00:33:37 by sid-bell          #+#    #+#             */
/*   Updated: 2019/02/19 05:42:34 by sid-bell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_cd(char *location, t_params *params)
{
	char	*dir;
	char	*old;
	t_stat	*stat;

	if (!location || !ft_strcmp(location, "~"))
		dir = ft_get_env_key("HOME", params->env);
	else if (location && !ft_strcmp(location, "-"))
		dir = ft_get_env_key("OLDPWD", params->env);
	else
		dir = location;
	old = ft_pwd();
	if ((stat = ft_exist(dir)))
	{
		if (S_ISDIR(stat->st_mode))
		{
			if (access(dir, X_OK))
			{
				ft_putendl_fd("Permission denied", 2);
				return ;
			}
			if (chdir(dir))
			{
				ft_putendl(dir);
				ft_putendl("Unknown error");
			}
			else
			{
				ft_setenv("OLDPWD", old, params);
				ft_setenv("PWD", ft_pwd(), params);
			}
		}
		else
		{
			ft_putstr(dir);
			ft_putendl(": Not a directory.");
		}
	}
	else
	{
		ft_putstr(dir);
		ft_putendl(": No such file or directory");
	}
}
