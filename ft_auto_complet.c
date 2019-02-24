/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_auto_complet.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sid-bell <sid-bell@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 00:33:37 by sid-bell          #+#    #+#             */
/*   Updated: 2019/02/24 07:25:42 by sid-bell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char		*ft_preview_color(char *str)
{
	char *resutl;

	str = ft_strjoin("\x1B[90m", str);
	resutl = ft_strjoin(str, "\x1b[0m");
	free(str);
	return (resutl);
}

char		*ft_getval(char *prefix, t_params *params)
{
	char *val;
	char *pwd;

	pwd = ft_pwd();
	val = NULL;
	val = ft_find_in_builtins(prefix);
	if (!val)
		val = ft_complete_dir(prefix, params);
	if (!val)
		val = ft_find_in_path(prefix, params);
	if (!val)
		val = ft_find_in_dir(pwd, prefix);
	free(pwd);
	if (val && !ft_strcmp(prefix, val))
	{
		free(val);
		return (NULL);
	}
	return (val);
}

static void	ft_helper(char **str, char *prefix, t_params *params,
						t_bool preview_mode)
{
	char	*val;
	char	*tmp;

	if ((val = ft_getval(prefix, params)))
	{
		if ((tmp = val) && preview_mode)
		{
			val = ft_preview_color(val + ft_strlen(prefix));
			free(tmp);
			tmp = *str;
			*str = ft_strjoin(*str, val);
		}
		else
		{
			tmp = *str;
			*str = ft_strjoin(*str, val + ft_strlen(prefix));
			free(tmp);
			tmp = *str;
			*str = ft_strjoin(*str, " ");
		}
		ft_put_to_stdin(*str, params, preview_mode);
		free(val);
		free(tmp);
	}
}

char		*ft_autocomplete(char *str, t_params *params, t_bool preview_mode)
{
	char	*prefix;

	if ((prefix = ft_getprefix(str)))
	{
		ft_helper(&str, prefix, params, preview_mode);
		free(prefix);
	}
	if (preview_mode)
	{
		free(str);
		return (NULL);
	}
	return (str);
}
