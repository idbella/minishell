/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isbuilt_in.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sid-bell <sid-bell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 00:33:37 by sid-bell          #+#    #+#             */
/*   Updated: 2019/02/17 19:21:49 by sid-bell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int ft_isbuilt_in(char *name)
{
	if (!ft_strcmp(name, "cd"))
		return (1);
	if (!ft_strcmp(name, "echo"))
		return (1);
	if (!ft_strcmp(name, "exit"))
		return (1);
	if (!ft_strcmp(name, "env"))
		return (1);
	if (!ft_strcmp(name, "setenv"))
		return (1);
	if (!ft_strcmp(name, "unsetenv"))
		return (1);
	return (0);
}
