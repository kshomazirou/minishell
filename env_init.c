/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shoumakobayashi <shoumakobayashi@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 20:38:05 by shoumakobay       #+#    #+#             */
/*   Updated: 2024/12/02 20:56:50 by shoumakobay      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "minishell.h"

int	env_init(t_mini *mini, char **env_s)
{
	t_env	*env;
	t_env	*new;
	int		i;

	env = ft_calloc(1, sizeof(t_env));
	if (!env)
		return (1);
	env->value = ft_strdup(env_s[0]);
	env->next = NULL;
	mini->env = env;
	mini->secret_env = env;
	i = 1;
	while (env_s && env_s[0] && env_s[i])
	{
		new = ft_calloc(1, sizeof(t_env));
		if (!new)
			return (1);
		new->value = ft_strdup(env_s[i]);
		new->next = NULL;
		env->next = new;
		i++;
	}
	return (0);
}
