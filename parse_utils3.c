/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shoumakobayashi <shoumakobayashi@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 09:57:48 by shoumakobay       #+#    #+#             */
/*   Updated: 2024/12/19 22:07:41 by shoumakobay      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
//here is changing 

t_token	*next_token(char *line, int *i)
{
	t_token	*token;
	int		j;
	char	c;

	j = 0;
	c = ' ';
	token = ft_calloc(1, sizeof(t_token));
	token->str = ft_calloc(1, sizeof(char) * next_alloc(line, i));
	if (!token || !token->str)
		return (NULL);
	while (line[*i] && (line[*i] != ' ' || c != ' '))
	{
		if (c == ' ' && (line[*i] == '\'' || line[*i] == '\"'))
			c = line[(*i)++];
		else if (c != ' ' && line[*i] == c)//here is strange 
		{
			c = ' ';
			(*i)++;
		}
		else if (line[*i] == '\\' && (*i)++)
			token->str[j++] = line[(*i)++];
		else
			token->str[j++] = line[(*i)++];
	}
	token->str[j] = '\0';
	return (token);
}

static int	is_last_valid_arg(t_token *token)
{
	t_token	*prev;

	if (!token || is_type(token, CMD) || is_type(token, ARG))
	{
		prev = prev_sep(token, NOSKIP);
		if (!prev || is_type(prev, END) || is_type(prev, PIPE))
			return (1);
		return (0);
	}
	else
		return (0);
}

void	squish_args2(t_mini *mini, t_token *token, t_token *prev)
{
	while (prev && is_last_valid_arg(prev) == 0)
		prev = prev->prev;
	if (token->prev != NULL)
		token->prev->next = token->next;
	if (token->next != NULL)
		token->next->prev = token->prev;
	token->prev = prev;
	if (prev != NULL)
	{
		token->next = prev->next;
		if (prev->next != NULL)
			prev->next->prev = token;
		prev->next = token;
	}
	else
	{
		token->next = mini->start;
		if (mini->start != NULL)
			mini->start->prev = token;
		mini->start = token;
	}
}

void	squish_args(t_mini *mini)
{
	t_token	*token;
	t_token	*prev;

	token = mini->start;
	while (token)
	{
		prev = prev_sep(token, NOSKIP);
		if (is_type(token, ARG) && is_types(prev, "TAI"))
			squish_args2(mini, token, prev);
		token = token->next;
	}
}
