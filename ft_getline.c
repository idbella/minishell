/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getline.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sid-bell <sid-bell@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 00:33:37 by sid-bell          #+#    #+#             */
/*   Updated: 2019/02/19 05:08:03 by sid-bell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_putstr2(char *str)
{
	ft_putstr_fd("\33[2K\r", 0);
	ft_putstr_fd("$> ", 0);
	ft_putstr_fd(str, 0);
}

char	*ft_backspace(char *str)
{
	char	*tmp;
	int		len;

	len = ft_strlen(str);
	tmp = str;
	str = ft_strsub(str, 0, len > 0 ? len - 1 : 0);
	ft_putstr2(str);
	free(tmp);
	return (str);
}

char	*ft_join(char *str, char *c, t_params *params)
{
	char	*tmp;
	int		len;

	if (*c == 127)
	{
		str = ft_backspace(str);
	}
	else if (*c == '\t')
	{
		len = ft_strlen(str);
		if (len && !ft_isspace(str[len - 1]))
			str = ft_autocomplete(str, params);
		else
		{
			tmp = str;
			str = ft_strjoin(str, c);
			ft_putstr2(str);
			free(tmp);
		}
	}
	else if (ft_isprint(*c))
	{
		tmp = str;
		str = ft_strjoin(str, c);
		ft_putstr2(str);
		free(tmp);
	}
	return (str);
}

char	*ft_getline(t_params *params)
{
	char			*str;
	char			*c;
	ssize_t			len;

	ft_setup_terminal();
	str = ft_strnew(0);
	c = ft_strnew(1);
	while (1)
	{
		len = read(0, c, 1);
		if (len > 0)
		{
			if (*c == '\n')
			{
				ft_putchar_fd('\n', 0);
				free(c);
				return (str);
			}
			str = ft_join(str, c, params);
		}
		else
			return (NULL);
	}
	return (NULL);
}
