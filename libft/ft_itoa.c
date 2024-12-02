/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shoumakobayashi <shoumakobayashi@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 21:29:12 by shoumakobay       #+#    #+#             */
/*   Updated: 2024/12/02 21:29:28 by shoumakobay      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../minishell.h"

static int	numlen(int n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		i++;
		n = n / 10;
	}
	return (i);
}

static void	numtochar(char *result, int n, int keta)
{
	if (keta > 1)
		numtochar(result, n / 10, keta - 1);
	result[keta - 1] = n % 10 + '0';
}

static void	minus_check(int *n, int *sign)
{
	if (*n < 0)
	{
		*sign = 1;
		*n = -(*n);
	}
}

char	*ft_itoa(int n)
{
	int		sign;
	int		len;
	char	*result;

	sign = 0;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	minus_check(&n, &sign);
	len = numlen(n);
	result = (char *)malloc(len + sign + 1);
	if (result == NULL)
		return (NULL);
	if (sign)
	{
		result[0] = '-';
		numtochar(result + 1, n, len);
	}
	else
		numtochar(result, n, len);
	result[len + sign] = '\0';
	return (result);
}