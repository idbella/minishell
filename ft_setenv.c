/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sid-bell <sid-bell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 00:33:37 by sid-bell          #+#    #+#             */
/*   Updated: 2019/02/18 14:49:30 by sid-bell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int ft_isvalid(char *key, char **val, t_list *list)
{
	int i;

	i = 0;
	if (!key || !val)
		ft_env(list);
	if (!*val)
		*val = ft_strnew(0);
	while (key[i])
	{
		if ((!ft_isalnum(key[i]) && key[i] != '_') || ft_isdigit(key[0]))
		{
			ft_putstr_fd("err - >",2);
			ft_putchar_fd(key[i], 2);
			ft_putchar_fd('\n',2);
			return (0);
		}
		i++;
	}
	return (1);
}

void	ft_setenv(char *key,char *value, t_params *params)
{
	t_env	*env;
	t_list	*list;
	t_list	*new;

	list = params->env;
	if (ft_isvalid(key, &value, params->env))
	{
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
}
