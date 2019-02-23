/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getprefix.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sid-bell <sid-bell@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 00:33:37 by sid-bell          #+#    #+#             */
/*   Updated: 2019/02/22 23:35:49 by sid-bell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_getprefix(char *str)
{
	char	**parts;
	char	*result;
	int		i;
	int		len;

	i = 0;
	len = ft_strlen(str);
	if (len && ft_isspace(str[len - 1]))
		return (NULL);
	parts = ft_strsplit(str, ' ');
	while (parts[i])
		i++;
	if (i == 0)
	{
		free(parts);
		return (NULL);
	}
	result = ft_strdup(parts[i - 1]);
	i = 0;
	while (parts[i])
		free(parts[i++]);
	free(parts);
	return (result);
}
