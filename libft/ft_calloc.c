/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ennollet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 10:14:20 by ennollet          #+#    #+#             */
/*   Updated: 2022/11/16 12:57:42 by ennollet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*tab;
	size_t	x;

	x = nmemb * size;
	if (x != 0 && x / nmemb != size)
		return (NULL);
	tab = (void *)malloc(x);
	if (!tab)
		return (NULL);
	ft_bzero(tab, x);
	return (tab);
}
