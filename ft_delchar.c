/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_delchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sid-bell <sid-bell@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 00:33:37 by sid-bell          #+#    #+#             */
/*   Updated: 2019/02/23 05:30:48 by sid-bell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_delchar(char **str, int index)
{
	char	*part1;
	char	*part2;
	char	*result;
	int		len;

	len = ft_strlen(*str);
	part1 = ft_strsub(*str, 0, index);
	part2 = ft_strsub(*str, index + 1, len - index);
	result = ft_strjoin(part1, part2);
	free(part1);
	free(part2);
	free(*str);
	return (result);
}
