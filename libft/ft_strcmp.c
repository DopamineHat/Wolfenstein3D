/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpagot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 02:09:53 by rpagot            #+#    #+#             */
/*   Updated: 2016/11/24 02:35:26 by adeletan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	unsigned char	*s3;
	unsigned char	*s4;
	size_t			index;

	index = 0;
	s3 = (unsigned char*)s1;
	s4 = (unsigned char*)s2;
	if (s3[index] != s4[index])
		return (s3[index] - s4[index]);
	while (s3[index] == s4[index] && (s3[index] && s4[index]))
		++index;
	if (s3[index] == s4[index])
		return (0);
	else
		return (s3[index] - s4[index]);
}
