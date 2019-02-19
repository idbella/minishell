/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_auto_complet.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sid-bell <sid-bell@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 00:33:37 by sid-bell          #+#    #+#             */
/*   Updated: 2019/02/19 05:09:50 by sid-bell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_getprefix(char *str)
{
	char	**parts;
	char	*result;
	int		i;

	i = 0;
	parts = ft_strsplit(str, ' ');
	while (parts[i])
		i++;
	if (i == 0)
		return (NULL);
	result = ft_strdup(parts[i - 1]);
	i = 0;
	while (parts[i])
		free(parts[i++]);
	free(parts);
	return (result);
}

char	*ft_find_in_dir(char *path, char *part0)
{
	DIR				*dir;
	struct dirent	*entry;

	if ((dir = opendir(path)))
	{
		while ((entry = readdir(dir)))
		{
			if (!ft_strncmp(part0, entry->d_name, ft_strlen(part0)))
				return (ft_strdup(entry->d_name));
		}
	}
	return (NULL);
}

char	*ft_find_in_path(char *part0, t_params *params)
{
	char			**paths;
	int				i;

	paths = ft_getpaths(params->env);
	i = 0;
	while (paths[i])
	{
		return (ft_find_in_dir(paths[i], part0));
		i++;
	}
	return (NULL);
}

char	*ft_find_in_builtins(char *tool)
{
	int 	len;
	char	**builtin;
	int 	count;

	count = 6;
	builtin = (char **)malloc(sizeof(char *) * 6);
	builtin[0] = ft_strdup("echo");
	builtin[1] = ft_strdup("env");
	builtin[2] = ft_strdup("setenv");
	builtin[3] = ft_strdup("unsetenv");
	builtin[4] = ft_strdup("cd");
	builtin[5] = ft_strdup("exit");

	len = ft_strlen(tool);
	while(count--)
		if (!ft_strncmp(builtin[count], tool, len))
			return (builtin[count]);
	return (NULL);
}

char	*ft_autocomplete(char *str, t_params *params)
{
	char *prefix;
	char *val;

	if ((prefix = ft_getprefix(str)))
	{
		if ((val = ft_find_in_builtins(prefix))
			|| (val = ft_find_in_path(prefix, params))
			|| (val = ft_find_in_dir(".", prefix)))
		{
			str = ft_strjoin(str, val + ft_strlen(str));
			ft_putstr2(str);
		}
	}
	return (str);
}
