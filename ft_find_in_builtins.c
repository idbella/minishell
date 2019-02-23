/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_in_builtins.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sid-bell <sid-bell@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 00:33:37 by sid-bell          #+#    #+#             */
/*   Updated: 2019/02/23 01:22:12 by sid-bell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_find_in_builtins(char *tool)
{
	int len;

	len = ft_strlen(tool);
	if (!ft_strncmp("echo", tool, len))
		return (ft_strdup("echo"));
	if (!ft_strncmp("env", tool, len))
		return (ft_strdup("env"));
	if (!ft_strncmp("setenv", tool, len))
		return (ft_strdup("setenv"));
	if (!ft_strncmp("unsetenv", tool, len))
		return (ft_strdup("unsetenv"));
	if (!ft_strncmp("cd", tool, len))
		return (ft_strdup("cd"));
	if (!ft_strncmp("exit", tool, len))
		return (ft_strdup("exit"));
	if (!ft_strncmp("history", tool, len))
		return (ft_strdup("history"));
	if (!ft_strncmp("unset_preview", tool, len))
		return (ft_strdup("unset_preview"));
	if (!ft_strncmp("set_preview", tool, len))
		return (ft_strdup("set_preview"));
	return (NULL);
}
