/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_parent.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sid-bell <sid-bell@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 00:33:37 by sid-bell          #+#    #+#             */
/*   Updated: 2019/02/23 22:52:44 by sid-bell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_get_parent_dir(char *dir)
{
	char	*pwd;
	char	*cdir;
	int		len;
	char	*parent;

	pwd = ft_pwd();
	if (!ft_strcmp(pwd, "/"))
		return (pwd);
	len = ft_strlen(dir);
	if (dir[len - 1] == '/')
		dir[len - 1] = '\0';
	cdir = ft_strrchr(dir, '/');
	len = len - ft_strlen(cdir);
	if (len > 0)
		parent = ft_strsub(dir, 0, len);
	else
		parent = ft_strdup("/");
	free(pwd);
	return (parent);
}
