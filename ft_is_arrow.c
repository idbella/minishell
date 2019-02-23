/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_arrow.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sid-bell <sid-bell@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 00:33:37 by sid-bell          #+#    #+#             */
/*   Updated: 2019/02/23 05:31:01 by sid-bell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_helper2(t_params *params, char **str, char c)
{
	int		len;

	len = ft_strlen(*str);
	if (c == 68)
	{
		params->pos += 1;
		*str = ft_delchar(str, len - params->pos);
	}
	else
	{
		*str = ft_delchar(str, len - params->pos - 1);
		params->pos -= 1;
	}
	if (c == 'A' || c == 'B')
		ft_browshistory(str, c, params);
}

static int	ft_helper1(t_params *params, char *last, char **str, char c)
{
	int len;
	int result;

	result = 0;
	if (last[0] == 27 && last[1] == 91)
	{
		if (c == 68 || c == 67 || c == 'A' || c == 'B')
		{
			ft_helper2(params, str, c);
			result = 1;
			len = ft_strlen(*str);
			if (params->pos > len)
				params->pos = len;
			else if (params->pos < 0)
				params->pos = 0;
			ft_put_to_stdin(*str, params, 0);
		}
	}
	last[2] = last[0];
	last[0] = last[1];
	last[1] = c;
	last[2] = 0;
	return (result);
}

int			ft_is_arrow(char c, char *last, t_params *params, char **str)
{
	int y;

	y = 0;
	if (!last[0])
		last[0] = c;
	else if (!last[1])
		last[1] = c;
	else
	{
		return (ft_helper1(params, last, str, c));
	}
	return (0);
}
