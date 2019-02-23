/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sid-bell <sid-bell@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 00:33:37 by sid-bell          #+#    #+#             */
/*   Updated: 2019/02/22 10:12:19 by sid-bell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
		entry = ft_strjoin(env->key, "=");
		env_str[index] = ft_strjoin(entry, env->value);
		free(entry);
		list = list->next;
		index++;
	}
	env_str[index] = NULL;
	return (env_str);
}
