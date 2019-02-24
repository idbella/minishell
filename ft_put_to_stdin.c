/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_to_stdin.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sid-bell <sid-bell@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 00:33:37 by sid-bell          #+#    #+#             */
/*   Updated: 2019/02/24 01:45:48 by sid-bell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		ft_put_to_stdin(char *str, t_params *params, t_bool preview_mode)
{
	int	i;

	ft_putstr_fd(CLEAR_LINE, 0);
	if (preview_mode)
		ft_putstr_fd(HIDE_CURSOR, 0);
	else
		ft_putstr_fd(SHOW_CURSOR, 0);
	ft_putstr_fd("$> ", 0);
	ft_putstr_fd(str, 0);
	i = params->pos;
	while (i-- > 0)
		ft_putstr_fd(MV_CURSOR, 0);
}
