/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstrim.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeletan <adeletan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 06:33:10 by adeletan          #+#    #+#             */
/*   Updated: 2016/11/24 02:40:43 by adeletan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strtrim(char const *s)
{
	char const *s2;

	if (s == NULL)
		return (NULL);
	while (*s == ' ' || *s == '\t' || *s == '\n')
		++s;
	if (*s == '\0')
		return (ft_strnew(0));
	s2 = s + ft_strlen(s) - 1;
	while (*s2 == ' ' || *s2 == '\t' || *s2 == '\n')
		s2--;
	return (ft_strsub(s, 0, s2 - s + 1));
}
