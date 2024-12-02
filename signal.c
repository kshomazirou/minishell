/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shoumakobayashi <shoumakobayashi@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 21:38:06 by shoumakobay       #+#    #+#             */
/*   Updated: 2024/12/02 21:38:25 by shoumakobay      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "minishell.h"

void	sig_int(int code)
{
	(void) code;

	if (g_sig.pid == 0)
	{
		write(1, "", 1);
		g_sig.exit_status = 1;
	}
	else
	{
		write(1, "", 1);
		g_sig.exit_status = 130;
	}
	g_sig.sigint = 1;
}

void	sig_quit(int code)
{
	char	*nbr;

	nbr = ft_itoa(code);
	if (g_sig.pid != 0)
	{
		write(1, "", 1);
		g_sig.exit_status = 131;
		g_sig.sigquit = 1;
	}
	else
		write(1, "", 1);
	ft_memdel(nbr);
}