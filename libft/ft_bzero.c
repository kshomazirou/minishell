/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shoumakobayashi <shoumakobayashi@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 20:48:31 by shoumakobay       #+#    #+#             */
/*   Updated: 2024/12/02 20:54:36 by shoumakobay      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../minishell.h"

static void	*ft_memset(void *buf, int ch, size_t n)
{
	size_t			num;
	unsigned char	*text;
	unsigned char	val;

	num = 0;
	text = (unsigned char *)buf;
	val = (unsigned char )ch;
	while (num < n)
	{
		text[num] = val;
		num++;
	}
	return (buf);
}

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}
