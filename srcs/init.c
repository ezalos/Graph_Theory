/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 17:30:55 by ldevelle          #+#    #+#             */
/*   Updated: 2019/02/19 15:02:09 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/head.h"

t_god	*first_init(void)
{
	//printf("%s\n", __func__);
	//char	*instruction;
	t_god	*god;

	god = NULL;
	if (!(god = create_struct(god, sizeof(t_god))))
		return(NULL);
	if (!(god->ver = (t_ver**)malloc(sizeof(t_ver*) * TOTAL_VERTICES)))
		return (NULL);
	parsing(god);
	return (god);
}
