/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_to_stdin.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sid-bell <sid-bell@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 00:33:37 by sid-bell          #+#    #+#             */
/*   Updated: 2019/02/23 06:59:34 by sid-bell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		ft_put_to_stdin(char *str, t_params *params, t_bool preview_mode)
{
	int	i;

	ft_putstr_fd("\33[2K\r", 0);
	if (preview_mode)
		ft_putstr_fd("\e[?25l", 0);
	else
		ft_putstr_fd("\e[?25h", 0);
	ft_putstr_fd("$> ", 0);
	ft_putstr_fd(str, 0);
	i = params->pos;
	while (i-- > 0)
		ft_putstr_fd("\033[D", 0);
}
