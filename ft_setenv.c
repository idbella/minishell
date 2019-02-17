/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sid-bell <sid-bell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 00:33:37 by sid-bell          #+#    #+#             */
/*   Updated: 2019/02/17 20:05:31 by sid-bell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_setenv(char *key,char *value, t_params *params)
{
	t_env	*env;
	t_list	*list;
	t_list	*new;

	list = params->env;
	if (!value)
		value = ft_strnew(0);
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
