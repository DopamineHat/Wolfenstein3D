/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_r.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apopinea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/27 12:14:39 by apopinea          #+#    #+#             */
/*   Updated: 2016/11/27 12:14:46 by apopinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

/*
**	op 	:
**	0	:	affiche erno.
**	1	:	affiche str.
**	2	:	affiche les deux.
**	op + ajouter deuxieme op
**	0	:	return 0 pour error_0 et null pour error_n
**	3	:	exit.
*/

void	*ft_error_n(int op, char *str, int ker)
{
	if (op % 3 == 0 || op % 3 == 2)
	{
		ft_putstr_fd("\033[31mPB \033[0m", 2);
		ft_putstr_fd(str, 2);
	}
	if (op % 3 == 1 || op % 3 == 2)
		ft_putstr_fd(strerror(ker), 2);
	ft_putchar_fd('\n', 2);
	if (op > 2)
		exit(ker);
	return (NULL);
}

int		ft_error_0(int op, char *str, int ker)
{
	if (op % 3 == 0 || op % 3 == 2)
	{
		ft_putstr_fd("\033[31mPB \033[0m", 2);
		ft_putstr_fd(str, 2);
	}
	if (op % 3 == 1 || op % 3 == 2)
		ft_putstr_fd(strerror(ker), 2);
	ft_putchar_fd('\n', 2);
	if (op > 2)
		exit(ker);
	return (0);
}
