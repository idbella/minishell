/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_complete_dir.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sid-bell <sid-bell@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 00:33:37 by sid-bell          #+#    #+#             */
/*   Updated: 2019/02/23 03:20:35 by sid-bell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*ft_helper(int len, char *part, char *fullpart, t_params *params)
{
	char	*dir;
	char	*new_dir;
	char	*result;

	dir = ft_strsub(fullpart, 0, len);
	if (dir[0] == '~')
	{
		new_dir = ft_gethome(dir, params);
		result = ft_find_in_dir(new_dir, part);
		free(new_dir);
	}
	else
		result = ft_find_in_dir(dir, part);
	if (result)
	{
		part = result;
		result = ft_strjoin(dir, result);
		free(part);
	}
	free(dir);
	return (result);
}

char		*ft_complete_dir(char *fullpart, t_params *params)
{
	char	*part;
	int		len;
	char	*result;

	len = ft_strlen(fullpart);
	part = ft_strrchr(fullpart, '/');
	if (part && (part += 1))
	{
		len = len - ft_strlen(part);
		result = ft_helper(len, part, fullpart, params);
		return (result);
	}
	return (NULL);
}
