/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shoumakobayashi <shoumakobayashi@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 20:42:51 by shoumakobay       #+#    #+#             */
/*   Updated: 2024/12/02 20:54:49 by shoumakobay      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../minishell.h"

char	*ft_strdup(const char *string)
{
	size_t	len;
	size_t	i;
	char	*buffer;

	i = 0;
	len = ft_strlen(string);
	buffer = (char *)malloc(len + 1);
	if (buffer == NULL)
		return (NULL);
	while (i < len)
	{
		buffer[i] = string[i];
		i++;
	}
	buffer[i] = '\0';
	return (buffer);
}
