/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isexec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sid-bell <sid-bell@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 00:33:37 by sid-bell          #+#    #+#             */
/*   Updated: 2019/02/22 06:00:09 by sid-bell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		ft_is_exec(char *file, char *path)
{
	t_stat		stat;
	int			val;

	val = 0;
	path = ft_strjoin(path, "/");
	file = ft_strjoin(path, file);
	if (!lstat(file, &stat))
	{
		if (S_ISREG(stat.st_mode) && !access(file, X_OK))
			val = 1;
	}
	free(path);
	free(file);
	return (val);
}
