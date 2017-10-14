/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpagot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 02:56:31 by rpagot            #+#    #+#             */
/*   Updated: 2016/11/24 02:38:20 by adeletan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t index;

	index = 0;
	if (n == 0)
		return (0);
	while ((s1[index] == s2[index]) && (s1[index] || s2[index])
			&& (--n > 0))
		index++;
	return ((unsigned char)s1[index] - (unsigned char)s2[index]);
}
