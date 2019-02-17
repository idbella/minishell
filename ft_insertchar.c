/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_insertchar.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sid-bell <sid-bell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 00:33:37 by sid-bell          #+#    #+#             */
/*   Updated: 2019/02/17 16:56:45 by sid-bell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_insertchar(char *str, char c, int index)
{
	int		i;
	char	*new;

	i = 0;
	new = ft_strnew(ft_strlen(str) + 1);
	while (str[i])
	{
		if (i == index)
		{
			new[i] = c;
		}else if (i > index)
			new[i] = str[i - 1];
		else
			new[i] = str[i];
		if (str[i + 1] == '\0')
			new[i + 1] = str[i];
		i++;
	}
	return (new);
}
