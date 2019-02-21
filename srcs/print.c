/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 17:30:52 by ldevelle          #+#    #+#             */
/*   Updated: 2019/02/19 12:58:11 by ldevelle         ###   ########.fr       */
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
	//printf("%s\n", __func__);
	int i;
	int len;
	int tmp;

	C_PURPLE
	printf("There is %d vertices\n", god->q_ver);
	C_RESET
	i = -1;
	len = 0;
	while (++i < god->q_ver)
		if (len < (tmp = ft_strlen(god->ver[i]->name)))
			len = tmp;
	i = -1;
	while (++i < god->q_ver)
	{
		ft_putnbr( god->ver[i]->serial_nb);
		C_PINK
		ft_putstr("\t: ");
		ft_putstr(god->ver[i]->name);
		//printf("%d\t: %s", god->ver[i]->serial_nb, god->ver[i]->name);
		ft_puttab(god->ver[i]->name, len + 1);
		C_RESET
		//god->ver[i]->serial_nb = i;
		if (god->ver[i]->edg->qlink)
			print_links(god, god->ver[i]);
		printf("\n");
	}
}
