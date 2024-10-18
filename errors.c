/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomas <tomas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 22:18:58 by tomas             #+#    #+#             */
/*   Updated: 2024/10/19 00:07:43 by tomas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "letters.h"

bool	check_argc(int argc)
{
	if (argc == 1)
	{
		ft_printf("Not Enaugh arguments");
		return (false);
	}
	if (argc > 2)
		ft_printf("Only the first argument is gonna be used :^)");
	return (true);
}

bool	check_input(char* argument, int argc)
{
	size_t	c;

	c = 0;
	if (!check_argc(argc))
		return (false);
	while (c < ft_strlen(argument))
	{
		if (!((argument[c] >= 'a' && argument[c] <= 'z') || (argument[c] >= 'A' && argument[c] <= 'Z')) && argument[c] != ' ')
		{
			ft_printf("The passing argument must be only letters of alphabet");
			return (false);
		}
		c++;
	}
	return (true);
}
