/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ennollet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 11:28:50 by ennollet          #+#    #+#             */
/*   Updated: 2022/11/15 13:26:41 by ennollet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	len;

	if (!dest && size == 0)
		return (0);
	i = 0;
	j = 0;
	len = ft_strlen(dest);
	if (size == 0 || size <= len)
		return (ft_strlen(src) + size);
	while (src[j] && len + i < size - 1)
	{
		dest[len + i] = src[j];
		i++;
		j++;
	}
	if (j < size)
		dest[len + i] = 0;
	if (size < len)
		return (ft_strlen(src) + size);
	return (len + ft_strlen(src));
}
/*
int main ()
{
	char *dst;
	dst = malloc(15);
	int i = -1;
	memset(dst, 0, 15);
	memset(dst, 'r', 6);
	memset(dst, 'r', 15);
	printf("%d\n%s", ft_strlcat(dst, "lorem ipsum dolor sit amet", 5), dst);
}*/
