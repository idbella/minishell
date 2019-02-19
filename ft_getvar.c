/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getvar.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sid-bell <sid-bell@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 00:33:37 by sid-bell          #+#    #+#             */
/*   Updated: 2019/02/19 05:29:17 by sid-bell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_getvarname(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (ft_isspace(str[i]) || str[i] == '\"')
			break ;
		i++;
	}
	return (ft_strsub(str, 0, i));
}

char	*ft_getvars(char *str, t_params *params)
{
	int		i;
	char	*nv;
	char	*key;
	int		qoute;

	i = 0;
	qoute = 0;
	while (str[i])
	{
		if (!qoute && str[i] == '$')
		{
			key = ft_getvarname(str + i + 1);
			if (!(nv = ft_get_env_key(key, params->env)))
				nv = ft_strnew(0);
			str = ft_strcut(str, i + 1, i + ft_strlen(key) + 1);
			str = ft_str_insert(str, nv, i);
			i += ft_strlen(nv) - 1;
		}
		if (str[i] == '\'')
			qoute = !qoute;
		i++;
	}
	return (str);
}
