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
#include <stdio.h>

void	ft_pwd()
{
	char *buff;

	buff = ft_strnew(255);
	getcwd(buff, 255);
	ft_putendl(buff);
}

char	**ft_getpaths(t_list *list)
{
	int		i;
	char	*path;
	i = 0;
	path = ft_get_env_key("PATH", list);
	return (ft_strsplit(path, ':'));
}

void	ft_cd(char *location)
{
	char *dir;

	if (location)
		dir = location;
	else
		dir = "~";
	if (chdir(dir))
	{
		ft_putendl(dir);
		ft_putendl(ft_strerror(errno));
	}
}

t_stat	*ft_exist(char *file)
{
	t_stat	*fstat;
	t_stat	*tmp;

	if (!(fstat = (t_stat *)malloc(sizeof(t_stat))))
		return (NULL);
	tmp = fstat;
	if (!stat(file, fstat))
		return (fstat);
	free(tmp);
	return (NULL);
}

void	ft_execute(char **cmd, t_params *params)
{
	int		pid;
	int		r_val;
	char	*file;
	char	**env;

	if ((file = ft_find_file(cmd[0], params->env)))
	{
		pid = fork();
		if (!pid)
		{
			env = ft_get_env(params->env);
			r_val = execve(file, cmd, env);
			if (r_val == -1)
				perror("ds");
		}
	}
}

void	ft_parse(char *command, t_params *params)
{
	char **cmd;

	cmd = ft_strsplit(command, ' ');
	if (cmd && cmd[0])
	{
		if (!ft_strcmp(cmd[0], "cd"))
			ft_cd(cmd[1]);
		else if (!ft_strcmp(cmd[0], "pwd"))
			ft_pwd();
		else
		{
			ft_execute(cmd, params);
		}
	}
}

void ft_catch(int signal)
{
	ft_putstr("signal = ");
	ft_putnbr(signal);
	ft_putchar('\n');
}

int		main(int argc, char **argv, char **env)
{
	char		*command;
	t_params	params;

	params.env = NULL;
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
