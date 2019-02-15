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
	struct s_env	*next;
}				t_env;
typedef struct	s_params
{
	char	**paths;
	t_env	*env;
}				t_params;
#endif
