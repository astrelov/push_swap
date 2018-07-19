/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astrelov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 18:57:54 by astrelov          #+#    #+#             */
/*   Updated: 2018/07/19 12:48:19 by null             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	len;
	size_t	res;

	res = ft_strlen(src);
	len = -1;
	while (dst[++len] && len < dstsize)
		;
	res += (len < dstsize) ? len : dstsize;
	if ((int)(dstsize - ft_strlen(dst) - 1) > 0)
		ft_strncat(dst, src, dstsize - ft_strlen(dst) - 1);
	return (res);
}
