/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcut.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sid-bell <sid-bell@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 00:33:37 by sid-bell          #+#    #+#             */
/*   Updated: 2019/02/20 04:26:11 by sid-bell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_strcut(char **str, int i0, int i1)
{
	char	*result;
	char	*part1;
	char	*part2;
	int		len;

	len = ft_strlen(*str);
	part1 = ft_strsub(*str, 0, i0);
	part2 = ft_strsub(*str, i1, len - i1);
	result = ft_strjoin(part1, part2);
	free(part1);
	free(part2);
	free(*str);
	return (result);
}
