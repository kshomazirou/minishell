/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shoumakobayashi <shoumakobayashi@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 20:28:30 by shoumakobay       #+#    #+#             */
/*   Updated: 2024/12/22 21:52:11 by shoumakobay      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "minishell.h"

//signal 
//exec cd / echo current / 
// 
// code explan 
// tokyo plannning


t_sig g_sig;

void minishell(t_mini *mini)//here is strange cmd is not done
{
	t_token	*token;
	int		status;

	token = next_run(mini->start, NOSKIP);
	if (is_types(mini->start, "TAI"))
		token = mini->start->next;
	while (mini->exit == 0 && token)
	{
		mini->charge = 1;//what is ?
		mini->parent = 1;//signal
		mini->last = 1;//
		redir_and_exec(mini, token);
		reset_std(mini);
		close_fds(mini);
		reset_fds(mini);
		waitpid(-1, &status, 0);
		status = WEXITSTATUS(status);
		if (mini->last == 0)
			mini->ret = status;
		if(mini->parent == 0)
		{
			free_token(mini->start);
			exit(mini->ret);
		}
		mini->no_exec = 0;
		token = next_run(token, SKIP);
	}
}

int main(int argc, char **argv, char **ev)
{
	t_mini	mini;

	(void)argc;
	(void)argv;

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
	while (1)
	{
		rl_set_prompt("");
		char *line = readline("> ");
		if (line == NULL || ft_strcmp(line, "exit") == 0)
			return (free(line), 0);
		g_sig.sigint = 0;
		g_sig.sigquit = 0;
		g_sig.pid = 0;
		g_sig.exit_status = 0;
		parse(&mini, line);
		if (mini.start != NULL && \
			check_line(&mini, mini.start))
			minishell(&mini);
		add_history(line);
	}
	// while (mini.exit == 0)//here is readline 
	// {
	// 	free_token(mini.start);
	// }
	free_env(mini.env);
	free_env(mini.secret_env);
	return (mini.ret);
}
