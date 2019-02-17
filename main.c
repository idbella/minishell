/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sid-bell <sid-bell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 00:33:37 by sid-bell          #+#    #+#             */
/*   Updated: 2019/02/17 07:30:31 by sid-bell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_unsetenv(char *key, t_params *params)
{
	t_env	*var1;
	t_list	*previous;
	t_list	*head;

	previous = NULL;
	head = params->env;
	if (head)
	{
		var1 = (t_env *)head->content;
		if (ft_strcmp(var1->key, key))
		{
			params->env = params->env->next;
			free(head);
		}
	}
	while (head)
	{
		var1 = (t_env *)head->content;
		if (!ft_strcmp(var1->key, key))
			break ;
		previous = head;
		head = head->next;
	}
	if (head && previous)
	{
		previous->next = head->next;
		free(head);
	}
}
int		main(int argc, char **argv, char **env)
{
	char		*command;
	t_params	params;
	char		*tmp;

	params.env = NULL;
	signal(SIGINT, ft_catch);
	ft_parse_env(env, &params);
	if (argc && argv)
		while (1)
		{
			ft_putstr("$> ");
			if (get_next_line(0, &command) != -1)
				ft_parse(command, &params);
		}
	return (0);
}
