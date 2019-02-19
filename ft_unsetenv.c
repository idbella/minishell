/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsetenv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sid-bell <sid-bell@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 00:33:37 by sid-bell          #+#    #+#             */
/*   Updated: 2019/02/19 05:20:04 by sid-bell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_unsetenv(char *key, t_params *params)
{
	t_list	*head;
	t_list	*prev;
	t_env	*env;

	head = params->env;
	prev = NULL;
	if (!key)
	{
		ft_putendl_fd("unsetenv: Too few arguments.", 2);
		return ;
	}
	while (params->env)
	{
		env = (t_env *)params->env->content;
		if (!ft_strcmp(env->key, key))
		{
			free(env);
			if (!prev)
			{
				params->env = head->next;
			}
			else
			{
				prev->next = params->env->next;
				free(params->env);
				params->env = head;
			}
			return ;
		}
		prev = params->env;
		params->env = params->env->next;
	}
	params->env = head;
}
