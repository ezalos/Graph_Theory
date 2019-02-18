/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 17:30:52 by ldevelle          #+#    #+#             */
/*   Updated: 2019/02/16 21:16:05 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/head.h"

void		print_links(t_god *god, t_ver *v0)
{
	//printf("%s\n", __func__);
	t_ver	*tmp;
	int		i;

	(void)god;
	if (v0->edg->qlink)
	{
		//ft_putstr("1");
		i = -1;
		while (++i < v0->edg->qlink)
		{
			//ft_putstr("@");
			tmp = (t_ver*)(ft_find_lsth(v0->edg->ver, i)->content);
			C_GREEN
			//ft_putstr("3");
			//	printf("%s\n", tmp->name);
			//printf("%d\n", tmp->serial_nb);
			//printf("%d\n", v0->edg->owner->serial_nb);
			//printf("%p\n", (void*)tmp);


			printf("%d->%d\t", v0->edg->owner->serial_nb, tmp->serial_nb);
			C_RESET
		}
	}
	//ft_putstr("4");
}

void		print_god_vert(t_god *god)
{
	printf("%s\n", __func__);
	int i;

	C_PURPLE
	printf("There is %d vertices\n", god->q_ver);
	i = -1;
	while (++i < god->q_ver)
	{
		C_PINK
		printf("%d\t: %s\t", god->ver[i]->serial_nb, god->ver[i]->name);
		C_RESET
		//god->ver[i]->serial_nb = i;
		//if (god->ver[i]->edg->qlink)
			print_links(god, god->ver[i]);
		printf("\n");
	}
}
