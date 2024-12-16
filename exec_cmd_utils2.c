/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd_utils2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shoumakobayashi <shoumakobayashi@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 21:40:20 by shoumakobay       #+#    #+#             */
/*   Updated: 2024/12/15 20:59:06 by shoumakobay      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	exec_bin(char **args, t_env *env, t_mini *mini)
{
	int		i;
	char	**bin;
	char	*path;
	int		ret;

	i = 0;
	ret = UNKNOWN_COMMAND;
	while (env && env->value && \
		ft_strncmp(env->value, "PATH=", 5) != 0)
		env = env->next;
	if (env == NULL || env->next == NULL)
		return (magic_box(args[0], args, env, mini));
	bin = ft_split(env->value, ':');
	if (!args[0] && !bin[0])
		return (ERROR);
	i = 1;
	path = check_dir(bin[0] + 5, args[0]);
	while (args[0] && bin[i] && path == NULL)
		path = check_dir(bin[i++], args[0]);
	if (path != NULL)
		ret = magic_box(path, args, env, mini);
	else
		ret = magic_box(args[0], args, env, mini);
	free_tab(bin);
	return (ft_memdel(path), ret);
}
