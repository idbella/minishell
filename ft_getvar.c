/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getvar.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sid-bell <sid-bell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 00:33:37 by sid-bell          #+#    #+#             */
/*   Updated: 2019/02/17 22:50:13 by sid-bell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_getvarname(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (ft_isspace(str[i]))
			break ;
		i++;
	}
	return (ft_strsub(str, 0, i));
}

char	*ft_getvars(char *str, t_params *params)
{
	int		i;
	char	*nv;
	char 	*key;

	i = 0;
	while (str[i])
	{
		if (str[i] == '$')
		{
			key = ft_getvarname(str + i + 1);
			if (!(nv = ft_get_env_key(key, params->env)))
				nv = ft_strnew(0);
			str = ft_strcut(str, i + 1, i + ft_strlen(key) + 1);
			str = ft_str_insert(str, nv, i);
			i += ft_strlen(nv) - 1;
		}
		i++;
	}
	return (str);
}
