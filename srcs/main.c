/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/20 12:12:02 by ldevelle          #+#    #+#             */
/*   Updated: 2019/02/21 13:54:49 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/head.h"

int		main(void)
{
	static t_god			*god;

	printf("%s\n", __func__);
	/*long long i = 2000000000;
	while (--i)
	{
		ft_rgb_color(-1, -1, -1);
		ft_putnstr(ft_nb_to_a(ft_random(0, 10000000000, 0, 1), 100), 0);
	}*/
	if (!(god = first_init()))
		return(-1);
	if (!(link_vertices(god)))
		return(-1);//*/
	return (0);
}
