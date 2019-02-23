/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_backspace.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sid-bell <sid-bell@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 00:33:37 by sid-bell          #+#    #+#             */
/*   Updated: 2019/02/23 05:29:36 by sid-bell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char		*ft_backspace(char *str, t_params *params)
{
	int		len;
	int		index;

	len = ft_strlen(str);
	if (len)
	{
		index = len - params->pos - 1;
		if (index >= 0)
		{
			str = ft_delchar(&str, index);
			ft_put_to_stdin(str, params, 0);
		}
	}
	return (str);
}
