/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gethome.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sid-bell <sid-bell@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 00:33:37 by sid-bell          #+#    #+#             */
/*   Updated: 2019/02/19 05:25:17 by sid-bell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_user_home(char *str)
{
	int		i;
	char	*user;
	char	*path;

	i = 0;
	while (str[i])
	{
		if (ft_isspace(str[i]))
			break ;
		i++;
	}
	user = ft_strsub(str, 0, i);
	path = ft_strjoin("/Users/", user);
	ft_putendl(path);
	if (!ft_exist(path))
	{
		free(user);
		free(path);
		return (NULL);
	}
	free(user);
	return (path);
}

char	*ft_gethome(char *str, t_params *params)
{
	int		i;
	int		qoute;
	char	*nv;

	qoute = 0;
	i = 0;
	while (str[i])
	{
		if (!qoute && str[i] == '~' &&
			((i > 0 && ft_isspace(str[i - 1])) || i == 0))
		{
			if (str[i + 1] && !ft_isspace(str[i + 1]) && str[i + 1] != '/')
			{
				if (!(nv = ft_user_home(str + i + 1)))
				{
					ft_putendl("Unknown user: ");
					i++;
					continue ;
				}
				else
					str = ft_strcut(str, i + 1, i + ft_strlen(nv) - 6);
			}
			else
				nv = ft_get_env_key("HOME", params->env);
			str = ft_str_insert(str, nv, i);
			i += ft_strlen(nv) - 1;
			qoute = 1;
		}
		else if (str[i] == '\"')
			qoute = !qoute;
		i++;
	}
	return (str);
}
