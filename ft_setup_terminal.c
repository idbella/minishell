/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setup_terminal.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sid-bell <sid-bell@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 00:33:37 by sid-bell          #+#    #+#             */
/*   Updated: 2019/02/24 04:52:36 by sid-bell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_setup_terminal(void)
{
	struct termios	mode;

	tcgetattr(0, &mode);
	mode.c_lflag = ~ECHO & mode.c_lflag;
	mode.c_lflag = ~ICANON & mode.c_lflag;
	mode.c_cc[VTIME] = 100;
	mode.c_cc[VMIN] = 0;
	tcsetattr(0, TCSANOW, &mode);
}

void	ft_reset_terminal(struct termios mode)
{
	tcsetattr(0, TCSANOW, &mode);
}
