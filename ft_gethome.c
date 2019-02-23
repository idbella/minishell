/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gethome.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sid-bell <sid-bell@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 00:33:37 by sid-bell          #+#    #+#             */
/*   Updated: 2019/02/22 08:25:58 by sid-bell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_gethome(char *str, t_params *params)
{
	int		i;
	int		qoute;
	char	*nv;
	char	*result;

	qoute = 0;
	i = 0;
	result = ft_strdup(str);
	if (!(nv = ft_get_env_key("HOME", params->env)))
		nv = ft_strnew(0);
	while (result[i])
	{
		if (!qoute && result[i] == '~' &&
			((i > 0 && ft_isspace(result[i - 1])) || i == 0))
		{
			result = ft_str_insert(&result, nv, i);
			i += ft_strlen(nv) - 1;
			qoute = 1;
		}
		else if (result[i] == '\"')
			qoute = !qoute;
		i++;
	}
	free(nv);
	return (result);
}
