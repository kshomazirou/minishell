/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shoumakobayashi <shoumakobayashi@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 21:27:17 by shoumakobay       #+#    #+#             */
/*   Updated: 2024/12/02 21:56:03 by shoumakobay      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "minishell.h"


// get_tokens
//squish_args is_type type_arg
void	parse(t_mini *mini)
{
	char	*line;
	t_token	*token;

	signal(SIGINT, &sig_int);
	signal(SIGQUIT, &sig_quit);
	ft_putstr_fd("\033[0;36m\033[1mminishell ▸ \033[0m", STDERR);
	if (get_next_line(0, &line) == -2 && (mini->exit = 1))//here is chnaged 
		ft_putendl_fd("exit", STDERR);
	if (g_sig.sigint == 1)
		mini->ret = g_sig.exit_status;
	if (quote_check(mini, &line))
		return ;
	line = space_line(line);
	if (line && line[0] == '$')
		line[0] = (char)(-line[0]);
	mini->start = get_tokens(line);
	ft_memdel(line);
	squish_args(mini);
	token = mini->start;
	while (token)
	{
		if (is_type(token, ARG))
			type_arg(token, 0);
		token = token->next;
	}
}
