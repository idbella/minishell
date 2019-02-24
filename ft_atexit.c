/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atexit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sid-bell <sid-bell@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 00:33:37 by sid-bell          #+#    #+#             */
/*   Updated: 2019/02/23 21:51:41 by sid-bell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_free_env(t_list *list)
{
	t_env *env;

	while (list)
	{
		env = (t_env *)list->content;
		free(env->key);
		free(env->value);
		list = list->next;
	}
}

void	ft_free_list(t_list *list)
{
	if (list->next)
		ft_free_list(list->next);
	free(list->content);
	free(list);
}

void	ft_atexit(t_params *params)
{
	free(params->pwd);
	tcsetattr(0, TCSANOW, &params->mode);
	ft_free_list(params->history);
	ft_free_env(params->env);
	ft_free_list(params->env);
}
