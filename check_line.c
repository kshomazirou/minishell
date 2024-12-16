/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shoumakobayashi <shoumakobayashi@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 10:40:19 by shoumakobay       #+#    #+#             */
/*   Updated: 2024/12/15 20:38:53 by shoumakobay      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_line(t_mini *mini, t_token *token)
{
	while (token)
	{
		if (is_types(token, "TAI")
			&& (!token->next || is_types(token->next, "TAIPE")))
		{
			ft_putstr_fd("bash: syntax error near unexpected token `", STDERR);
			if (token->next)
				ft_putstr_fd(token->next->str, STDERR);
			else
				ft_putstr_fd("newline", STDERR);
			mini->ret = 258;
			return (ft_putendl_fd("'", STDERR), 0);
		}
		if (is_types(token, "PE")
			&& (!token->prev || !token->next || is_types(token->prev, "TAIPE")))
		{
			ft_putstr_fd("bash: syntax error near unexpected token `", STDERR);
			ft_putstr_fd(token->str, STDERR);
			mini->ret = 258;
			return (ft_putendl_fd("'", STDERR), 0);
		}
		token = token->next;
	}
	return (1);
}
