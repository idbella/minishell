/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sid-bell <sid-bell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 00:33:37 by sid-bell          #+#    #+#             */
/*   Updated: 2019/02/16 10:44:14 by sid-bell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_parse_env(char **env, t_params *params)
{
	int		index;
	char	*key;
	char	*value;
	int		i;

	index = 0;
	while (env[index])
	{
		i = 0;
		while(env[index][i])
		{
			if (env[index][i] == ':' || env[index][i] == '=')
			{
				key = ft_strsub(env[index], 0, i++);
				break;
			}
			i++;
		}
		value = ft_strsub(env[index], i, ft_strlen(env[index]));	
		ft_setenv(key, value, params);
		index++;
	}
}

void	ft_setenv(char *key,char *value, t_params *params)
{
	t_env	*env;
	t_list	*list;
	t_list	*new;

	list = params->env;
	while (list)
	{
		env = (t_env *)list->content;
		if (!ft_strcmp(env->key, key))
		{
			free(env->value);
			env->value = value;
			return ;
		}
		list = list->next;
	}
	env = (t_env *)malloc(sizeof(t_env));
	env->key = key;
	env->value = value;
	new = ft_lstnew(NULL, 0);
	new->content = env;
	ft_lstadd(&params->env, new);
}

char	**ft_get_env(t_list *list)
{
	char	**env_str;
	t_env	*env;
	char	*entry;
	int		index;

	env = NULL;
	env_str = (char **)malloc(sizeof(char *) * ft_lstcount(list) + 1);
	index = 0;
	while (list)
	{
		env = (t_env *)list->content;
		entry = ft_strjoin(env->key, ":");
		env_str[index] = ft_strjoin(entry, env->value);
		free(entry);
		list = list->next;
		index++;
	}
	env_str[index] = NULL;
	return (env_str);
}

char	*ft_get_env_key(char *key, t_list *list)
{
	t_env *env;

	env = NULL;
	while (list)
	{
		env = (t_env *)list->content;
		if (!ft_strcmp(env->key, key))
			return (env->value);
		list = list->next;
	}
	return (NULL);
}

void	ft_env(t_list *list)
{
	char **env;

	env = ft_get_env(list);
	while(*env)
	{
		ft_putendl(*env);
		env++;
	}
}
