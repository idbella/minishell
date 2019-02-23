/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_env_key.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sid-bell <sid-bell@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 00:33:37 by sid-bell          #+#    #+#             */
/*   Updated: 2019/02/21 23:24:52 by sid-bell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_get_env_key(char *key, t_list *list)
{
	t_env *env;

	env = NULL;
	while (list)
	{
		env = (t_env *)list->content;
		if (!ft_strcmp(env->key, key))
			return (ft_strdup(env->value));
		list = list->next;
	}
	return (NULL);
}
