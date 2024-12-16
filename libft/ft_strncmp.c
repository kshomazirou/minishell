/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shoumakobayashi <shoumakobayashi@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 21:51:17 by shoumakobay       #+#    #+#             */
/*   Updated: 2024/12/04 21:51:42 by shoumakobay      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../minishell.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	num;

	num = 0;
	while (n > num && (s1[num] != '\0' || s2[num] != '\0'))
	{
		if ((unsigned char)s1[num] != (unsigned char)s2[num])
			return ((unsigned char)s1[num] - (unsigned char)s2[num]);
		num++;
	}
	return (0);
}
