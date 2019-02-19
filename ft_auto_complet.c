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

char	*ft_find_in_path(char *part0, t_params *params)
{
	DIR				*dir;
	char			**paths;
	int				i;
	struct dirent	*entry;

	paths = ft_getpaths(params->env);
	i = 0;
	while (paths[i])
	{
		if ((dir = opendir(paths[i])))
		{
			while ((entry = readdir(dir)))
			{
				if (!ft_strncmp(part0, entry->d_name, ft_strlen(part0)))
					return (ft_strdup(entry->d_name));
			}
		}
		i++;
	}
	return (NULL);
}

char	*ft_autocomplete(char *str, t_params *params)
{
	char *prefix;
	char *val;

	if ((prefix = ft_getprefix(str)))
	{
		if ((val = ft_find_in_path(prefix, params)))
		{
			str = ft_strjoin(str, val + ft_strlen(str));
			ft_putstr2(str);
		}
	}
	return (str);
}
