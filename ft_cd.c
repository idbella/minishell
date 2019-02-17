/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sid-bell <sid-bell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 00:33:37 by sid-bell          #+#    #+#             */
/*   Updated: 2019/02/16 22:46:19 by sid-bell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_cd(char *location, t_params *params)
{
	char	*dir;
	char	*old;

	if (!location || !ft_strcmp(location, "~"))
		dir = ft_get_env_key("HOME", params->env);
	else if (location && !ft_strcmp(location, "-"))
		dir = ft_get_env_key("OLDPWD", params->env);
	else
		dir = location;
	old = ft_pwd();
	if (chdir(dir))
	{
		ft_putendl(dir);
		ft_putendl(ft_strerror(errno));
	}
	else
	{
		ft_setenv("OLDPWD", old, params);
		ft_setenv("PWD", ft_pwd(), params);
	}
}
