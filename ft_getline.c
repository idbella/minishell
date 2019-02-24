/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getline.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sid-bell <sid-bell@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 00:33:37 by sid-bell          #+#    #+#             */
/*   Updated: 2019/02/24 01:11:52 by sid-bell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*ft_strinsert(char *str1, char *filler, int index)
{
	char	*result;
	char	*part1;
	char	*part2;
	int		len;

	len = ft_strlen(str1);
	part1 = ft_strsub(str1, 0, index);
	part2 = ft_strsub(str1, index, len - index);
	result = ft_strjoin(part1, filler);
	free(part1);
	part1 = result;
	result = ft_strjoin(result, part2);
	free(part1);
	free(part2);
	return (result);
}

static void	ft_helper(char *c, char **str, t_params *params)
{
	int		len;
	char	*tmp;

	len = ft_strlen(*str);
	if (params->pos == 0 && len && !ft_isspace((*str)[len - 1]))
		*str = ft_autocomplete(*str, params, 0);
	else
	{
		len = ft_strlen(*str) - params->pos;
		if (len >= 0)
		{
			tmp = *str;
			*str = ft_strinsert(*str, c, len);
			ft_put_to_stdin(*str, params, 0);
			free(tmp);
		}
	}
}

char		*ft_handle_input(char *str, char *c, t_params *params)
{
	char	*tmp;
	int		len;

	if (!*str)
		params->pos = 0;
	if (*c == 127)
	{
		str = ft_backspace(str, params);
	}
	else if (*c == '\t')
	{
		ft_helper(c, &str, params);
	}
	else if (ft_isprint(*c))
	{
		len = ft_strlen(str) - params->pos;
		if (len >= 0)
		{
			tmp = str;
			str = ft_strinsert(str, c, ft_strlen(str) - params->pos);
			ft_put_to_stdin(str, params, 0);
			free(tmp);
		}
	}
	return (str);
}

void		ft_setup(char *last, char **c, t_params *params)
{
	ft_bzero(last, 3);
	if (!g_line)
		g_line = ft_strnew(0);
	*c = ft_strnew(1);
	params->pos = 0;
}

char		*ft_getline(t_params *params)
{
	char			*c;
	char			last[3];

	ft_setup(last, &c, params);
	while (1)
		if (read(0, c, 1))
		{
			if (*c == '\n')
			{
				params->history_pos = -1;
				ft_put_to_stdin(g_line, params, 0);
				ft_putchar_fd('\n', 0);
				free(c);
				return (g_line);
			}
			if (ft_is_arrow(*c, last, params, &g_line))
				continue ;
			g_line = ft_handle_input(g_line, c, params);
			if (params->preview_mode && params->pos == 0)
				ft_autocomplete(ft_strdup(g_line), params, 1);
		}
		else
			ft_bzero(c, 0);
	return (NULL);
}
