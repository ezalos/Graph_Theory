/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/20 12:12:02 by ldevelle          #+#    #+#             */
/*   Updated: 2019/02/16 14:51:31 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/head.h"

int		main(void)
{
	static t_god			*god;

	printf("%s\n", __func__);
	if (!(god = first_init()))
		return(-1);
	if (!(link_vertices(god)))
		return(-1);
	return (0);
}
