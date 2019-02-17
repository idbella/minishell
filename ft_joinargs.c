/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_joinargs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sid-bell <sid-bell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 00:33:37 by sid-bell          #+#    #+#             */
/*   Updated: 2019/02/17 17:12:49 by sid-bell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_joinargs(char *str)
{
	int i;
	int r;
	int	qoute;

	qoute = 0;
	i = 0;
	r = 0;
	while (str[i])
	{
		if (!qoute && !ft_isspace(str[i]) && str[i + 1] == '\"')
		{
            r = i;
            while (r >= 0)
            {
                if (str[r] == '\"' || ft_isspace(str[r]))
                    break ;
                r--;
            }
			str = ft_delchar(str, i + 1);
			str = ft_insertchar(str, '\"', r + 1);
            qoute = 1;
			i++;
		}
		if (str[i] == '\"')
			qoute = !qoute;
		i++;
	}
    return (str);
}
