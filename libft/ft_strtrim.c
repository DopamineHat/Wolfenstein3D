/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpagot <rpagot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 22:26:21 by rpagot            #+#    #+#             */
/*   Updated: 2016/11/18 22:26:23 by rpagot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_space(char const *s, int *i2, int *i3)
{
	int i;

	i = 0;
	while (s[i])
		++i;
	if (i != 0)
		--i;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		--i;
	if (i == -1)
	{
		*i2 = 1;
		*i3 = 0;
		return (0);
	}
	*i3 = i;
	i = 0;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		++i;
	*i2 = i;
	return (*i3 - *i2 + 1);
}

char		*ft_strtrim(char const *s)
{
	char	*array;
	int		i2;
	int		i3;
	int		i4;

	if (!(s))
		return (NULL);
	i4 = ft_count_space(s, &i2, &i3);
	if (!(array = (char*)malloc((i4 + 1) * sizeof(char))))
		return (NULL);
	i4 = 0;
	while (i2 <= i3)
		array[i4++] = s[i2++];
	array[i4] = '\0';
	return (array);
}
