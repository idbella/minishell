/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsetenv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sid-bell <sid-bell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 00:33:37 by sid-bell          #+#    #+#             */
/*   Updated: 2019/02/17 21:21:22 by sid-bell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void    ft_unsetenv(char *key, t_params *params)
{
	t_list	*head;
	t_list	*prev;
	t_env	*env;

	head = params->env;
	prev = NULL;
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
				params->env = head;
				free(params->env);
			}
			return ;
		}
		prev = params->env;
		params->env = params->env->next;

	}
}
