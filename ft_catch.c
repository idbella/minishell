/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_catch.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sid-bell <sid-bell@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 00:33:37 by sid-bell          #+#    #+#             */
/*   Updated: 2019/02/24 01:00:02 by sid-bell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_catch(int signal)
{
	if (signal)
	{
		ft_putchar('\n');
		if (!g_waiting)
		{
			ft_putstr("$> ");
			if (g_line)
			{
				free(g_line);
				g_line = ft_strnew(0);
			}
		}
		g_waiting = 0;
	}
}
