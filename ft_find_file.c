/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sid-bell <sid-bell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 00:33:37 by sid-bell          #+#    #+#             */
/*   Updated: 2019/02/16 22:49:35 by sid-bell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_find_file(char *file, t_list *list)
{
	char	**paths;
	int		index;
	char	*fullpath;
	char	*tmp;

	index = 0;
	if (ft_exist(file))
		return (file);
	paths = ft_getpaths(list);
	while(paths[index])
	{
		fullpath = ft_strjoin(paths[index], "/");
		tmp = fullpath;
		fullpath = ft_strjoin(fullpath, file);
		free(tmp);
		if (ft_exist(fullpath))
			return (fullpath);
		index++;
	}
	return (NULL);
}

t_stat	*ft_exist(char *file)
{
	t_stat	*fstat;
	t_stat	*tmp;

	if (!(fstat = (t_stat *)malloc(sizeof(t_stat))))
		return (NULL);
	tmp = fstat;
	if (!stat(file, fstat))
		return (fstat);
	free(tmp);
	return (NULL);
}
