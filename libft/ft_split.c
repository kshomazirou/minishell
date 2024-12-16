/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shoumakobayashi <shoumakobayashi@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 21:48:52 by shoumakobay       #+#    #+#             */
/*   Updated: 2024/12/04 21:52:06 by shoumakobay      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../minishell.h"

size_t	deli_count(char const *s, char c)
{
	size_t	len;
	size_t	i;
	int		separator;

	i = 0;
	len = 0;
	separator = 1;
	while (s[i])
	{
		if (s[i] == c)
		separator = 1;
		else if (separator)
		{
			len++;
			separator = 0;
		}
		i++;
	}
	return (len);
}

static void	result_free(char **result, int j)
{
	while (j-- > 0)
		free(result[j]);
	free(result);
}

static char	**repeat(char const *s, char c, char **result)
{
	size_t	i;
	size_t	sub_len;

	i = 0;
	while (*s)
	{
		if (*s != c)
		{
			sub_len = 0;
			while (*s && *s != c && ++sub_len)
				++s;
			result[i] = ft_substr(s - sub_len, 0, sub_len);
			if (result[i++] == NULL)
				return (result_free(result, i), NULL);
		}
		else
			++s;
	}
	result[i] = NULL;
	return (result);
}

char	**ft_split(char const *s, char c)
{
	char	**result;

	if (s == NULL)
		return (NULL);
	result = (char **)malloc((deli_count(s, c) + 1) * sizeof(char *));
	if (result == NULL)
		return (NULL);
	result = repeat(s, c, result);
	return (result);
}
