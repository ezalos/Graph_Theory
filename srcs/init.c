/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 17:30:55 by ldevelle          #+#    #+#             */
/*   Updated: 2019/02/16 14:47:53 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/head.h"

t_god	*first_init(void)
{
	printf("%s\n", __func__);
	char	*instruction;
	t_god	*god;

	god = NULL;
	if (!(god = create_struct(god, sizeof(t_god))))
		return(NULL);
	if (!(god->ver = (t_ver**)malloc(sizeof(t_ver*) * TOTAL_VERTICES)))
		return (NULL);
	C_ORANGE
	printf("Please name your new vetice\n");
	C_CYAN
	if (0 >= get_next_line(0, &instruction))
		return (NULL);
	C_RESET
	while (instruction[0] != '\0')
	{
		C_MAGENTA
		printf("Here's the string: %s\n", instruction);
		C_RESET
		create_vertice(god, instruction);
		ft_strdel(&instruction);
		C_ORANGE
		printf("Please name your new vetice\n");
		C_CYAN
		if (0 >= get_next_line(0, &instruction))
			return (NULL);
		C_RESET
	}
	return (god);
}
