/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shoumakobayashi <shoumakobayashi@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 20:28:30 by shoumakobay       #+#    #+#             */
/*   Updated: 2024/12/02 22:06:22 by shoumakobay      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "minishell.h"

int main(int argc, char **argv, char **ev)
{
	t_mini	mini;

	(void)argc;
	(void)argv;

	mini.in = dup(STDIN);
	mini.out = dup(STDOUT);
	mini.exit = 0;
	mini.ret = 0;
	mini.no_exec = 0;
	mini.fdin = -1;
	mini.fdout = -1;
	mini.pipin = -1;
	mini.pipout = -1;
	mini.pid = -1;
	env_init(&mini, ev);
	shell_level(mini.env);
	// while (mini.exit == 0)//here is readline 
	// {
		g_sig.sigint = 0;
		g_sig.sigquit = 0;
		g_sig.pid = 0;
		g_sig.exit_status = 0;
		parse(&mini);
	// 	if (mini.start != NULL && \
	// 		check_line(&mini, mini.start))
	// 		minishell(&mini);
	// 	free_token(mini.start);
	// }
	// free_env(mini.env);
	// free_env(mini.secret_env);
	return (mini.ret);
}
