/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   link.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 14:19:22 by ldevelle          #+#    #+#             */
/*   Updated: 2019/02/16 21:14:26 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/head.h"

void		add_ver_in_edg(t_ver *v0, t_ver *v1)
{
	printf("%s\n", __func__);

	if (!v0->edg->ver)
	{
		printf("if NULL\n");
		v0->edg->ver = ft_lstnew_ptr(v1, sizeof(*v1));
	}
	else
	{
		printf("if !NULL\n");
		ft_lstadd_end(v0->edg->ver, ft_lstnew_ptr(v1, sizeof(*v1)));
	}
	v0->edg->qlink++;
	printf("%dqlink: %d\n", v0->serial_nb, v0->edg->qlink);
}

void	add_vers_in_edgs(t_ver *v0, t_ver *v1)
{
	printf("%s\n", __func__);

	add_ver_in_edg(v0, v1);
	add_ver_in_edg(v1, v0);
}

void	*link_vertices(t_god *god)
{
	printf("%s\n", __func__);
	char	*ver_one;
	char	*ver_two;

	print_god_vert(god);
	C_YELLOW
	printf("Please choose 2 vertices\n");
	C_RESET
	C_CYAN
	if (0 >= get_next_line(0, &ver_one))
		return (NULL);
	printf("ver_one: |%s|\n", ver_one);
	if (0 >= get_next_line(0, &ver_two))
		return (NULL);
	printf("ver_two: |%s|\n", ver_two);
	C_RESET
	while (ver_one[0] != '\0' || ver_two[0] != '\0')
	{
		printf("NUMBER CHOOSED : %s-%d & %s-%d\n", ver_one, atoi(ver_one), ver_two, atoi(ver_two));
		add_vers_in_edgs(god->ver[ft_atoi(ver_one)], god->ver[ft_atoi(ver_two)]);
		ft_strdel(&ver_one);
		ft_strdel(&ver_two);
		print_god_vert(god);
		C_CYAN
		if (0 >= get_next_line(0, &ver_one))
			return (NULL);
		printf("ver_one: |%s|\n", ver_one);
		if (0 >= get_next_line(0, &ver_two))
			return (NULL);
		printf("ver_two: |%s|\n", ver_two);
		C_RESET
	}
	return (god);
}
