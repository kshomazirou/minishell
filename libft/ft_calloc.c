/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shoumakobayashi <shoumakobayashi@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 20:51:28 by shoumakobay       #+#    #+#             */
/*   Updated: 2024/12/02 20:54:45 by shoumakobay      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../minishell.h"

void	*ft_calloc(size_t n, size_t size)
{
	void	*box;

	if (!n || !size)
	{
		n = 1;
		size = 1;
	}
	if (SIZE_MAX / n < size)
		return (malloc(0));
	box = (void *)malloc(n * size);
	if (box == NULL)
		return (NULL);
	ft_bzero(box, n * size);
	return (box);
}
