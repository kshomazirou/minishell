/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shoumakobayashi <shoumakobayashi@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 10:28:54 by shoumakobay       #+#    #+#             */
/*   Updated: 2024/12/03 10:29:39 by shoumakobay      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../minishell.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t n)
{
	size_t	num;

	num = 0;
	if (n == 0)
		return (ft_strlen(src));
	while (src[num] != '\0' && n - 1 > num)
	{
		dest[num] = src[num];
		num++;
	}
	if (num < n)
		dest[num] = '\0';
	while (src[num] != '\0')
		num++;
	return (num);
}

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dnum;
	size_t	snum;
	size_t	cpy_size;
	size_t	i;

	dnum = 0;
	snum = 0;
	if (size == 0)
		return (ft_strlen(src));
	while (dst[dnum] != '\0' && dnum < size)
		dnum++;
	while (src[snum] != '\0')
		snum++;
	cpy_size = size - dnum - 1;
	if (size <= dnum)
		return (dnum + snum);
	i = 0;
	while (src[i] != '\0' && cpy_size > i)
	{
		dst[dnum + i] = src[i];
		i++;
	}
	dst[dnum + i] = '\0';
	return (dnum + snum);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*ret;
	size_t	len;

	if (!s1 || !s2)
		return (0);
	len = ft_strlen(s1) + ft_strlen(s2);
	ret = malloc(sizeof(char) * (len + 1));
	if (!ret)
		return (0);
	ft_strlcpy(ret, s1, len + 1);
	ft_strlcat(ret, s2, len + 1);
	return (ret);
}
