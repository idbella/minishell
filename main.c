/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sid-bell <sid-bell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 00:33:37 by sid-bell          #+#    #+#             */
/*   Updated: 2019/02/15 23:52:39 by sid-bell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**ft_getpaths(char **env);
void	ft_pwd();
void	ft_cd(char *location);
t_stat	*ft_exist(char *file);
char	*ft_find_file(char *file, char **env);
void	ft_execute(char **cmd, char **env);
void	ft_parse(char *command, char **env);
void	ft_catch(int signal);
#include <stdio.h>

void	ft_pwd()
{
	char *buff;

	buff = ft_strnew(255);
	getcwd(buff, 255);
	ft_putendl(buff);
}

char	**ft_getpaths(char **env)
{
	int		i;

	i = 0;
	while (env[i])
	{
		if (!ft_strncmp(env[i], "PATH=", 5))
		{
			return (ft_strsplit(env[i] + 5, ':'));
		}
		i++;
	}
	return (NULL);
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
		ft_putendl("Error");
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

char	*ft_find_file(char *file, char **env)
{
	char	**paths;
	int		index;
	char	*fullpath;
	char	*tmp;

	index = 0;
	paths = ft_getpaths(env);
	while(paths[index])
	{
		fullpath = ft_strjoin(paths[index], "/");
		tmp = fullpath;
		fullpath = ft_strjoin(fullpath, file);
		free(tmp);
		if (ft_exist(fullpath))
			return (fullpath);
		index++;
	}
	return (NULL);
}

void	ft_execute(char **cmd, char **env)
{
	int		pid;
	int		r_val;
	char	*file;

	
	if ((file = ft_find_file(cmd[0], env)))
	{
		pid = fork();
		if (!pid)
		{
			r_val = execve(file, cmd, env);
			if (r_val == -1)
				perror("ls ");
		}
	}
}

void	ft_parse(char *command, char **env)
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
			ft_execute(cmd, env);
	}
}

void ft_catch(int signal)
{
	ft_putstr("signal = ");
	ft_putnbr(signal);
	ft_putchar('\n');
}

void	ft_parse_env(char **env, t_env *envir)
{
	int index;

	index = 0;
	while (env[index])
	{
		envir = (t_env *)malloc(sizeof(t_env));
		index++;
	}
}
void	ft_setenv(char *key,char *value, t_env *env)
{
	while (env)
	{
		if (!ft_strcmp(env->key, key))
		{
			free(env->value);
			env->value = ft_strdup(value);
			return ;
		}
		env = env->next;
	}
	env = (t_env *)malloc(sizeof(t_env));
	env->key = key;
	env->value = value;
}

int		main(int argc, char **argv, char **env)
{
	char		*command;
	t_params	params;

	params.paths = ft_getpaths(env);
	if (argc && argv)
		while (1)
		{
			ft_putstr("$> ");
			if (get_next_line(0, &command) != -1)
			ft_parse(command, env);
		}
	return (0);
}
