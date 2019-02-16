/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sid-bell <sid-bell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 16:53:34 by sid-bell          #+#    #+#             */
/*   Updated: 2019/02/15 23:46:11 by sid-bell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include <dirent.h>
# include "libft/libft.h"
# include <sys/stat.h>
# include <errno.h>

typedef char		t_bool;
typedef struct stat	t_stat;
typedef struct	s_env
{
	char			*key;
	char			*value;
}				t_env;
typedef struct	s_params
{
	t_list	*env;
}				t_params;
void	ft_parse_env(char **env, t_params *params);
void	ft_setenv(char *key,char *value, t_params *params);
void	ft_env(t_list *list);
char	**ft_getpaths(t_list *list);
void	ft_pwd();
void	ft_cd(char *location);
t_stat	*ft_exist(char *file);
char	*ft_find_file(char *file, t_list *list);
void	ft_execute(char **cmd, t_params *params);
void	ft_parse(char *command, t_params *params);
void	ft_catch(int signal);
char	**ft_get_env(t_list *list);
char	*ft_get_env_key(char *key, t_list *list);
#endif
