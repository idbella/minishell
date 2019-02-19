/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setup_terminal.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sid-bell <sid-bell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 00:33:37 by sid-bell          #+#    #+#             */
/*   Updated: 2019/02/18 20:21:18 by sid-bell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_setup_terminal(void)
{
	struct termios	mode;

	tcgetattr(0, &mode);
	mode.c_lflag &= ~(ICANON | ECHO);
	tcsetattr(0, TCSANOW, &mode);
}

void	ft_reset_terminal(struct termios mode)
{
	tcsetattr(0, TCSANOW, &mode);
}
