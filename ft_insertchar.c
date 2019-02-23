/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_insertchar.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sid-bell <sid-bell@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 00:33:37 by sid-bell          #+#    #+#             */
/*   Updated: 2019/02/23 05:54:43 by sid-bell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_insertchar(char **src, char c, int index)
{
	int		i;
	char	*new;
	char	*str;

	str = *src;
	i = 0;
	new = ft_strnew(ft_strlen(str) + 1);
	while (str[i])
	{
		if (i == index)
		{
			new[i] = c;
		}
		else if (i > index)
			new[i] = str[i - 1];
		else
			new[i] = str[i];
		if (str[i + 1] == '\0')
			new[i + 1] = str[i];
		i++;
	}
	free(*src);
	return (new);
}
