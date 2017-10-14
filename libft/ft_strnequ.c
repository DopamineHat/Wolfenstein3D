/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeletan <adeletan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 07:34:39 by adeletan          #+#    #+#             */
/*   Updated: 2016/11/24 02:38:39 by adeletan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	size_t index;

	if (s1 == NULL || s2 == NULL)
		return (0);
	index = 0;
	while ((index < n) && (s1[index] && s2[index]))
	{
		if (s1[index] == s2[index])
			index++;
		else
			return (0);
	}
	if (s1[index - 1] == s2[index - 1])
		return (1);
	else
		return (0);
}
