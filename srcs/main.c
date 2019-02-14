/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/20 12:12:02 by ldevelle          #+#    #+#             */
/*   Updated: 2019/02/14 19:50:59 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/head.h"

void	*create_struct(void *ptr, size_t size)
{
	printf("%s\n", __func__);
	if (!(ptr = malloc(size)))
		return (NULL);
	ft_bzero(ptr, size);
	return(ptr);
}

t_ver	*create_vertice(char *name)
{
	printf("%s\n", __func__);
	t_ver	*ptr;

	ptr = NULL;
	if (!(create_struct(ptr, sizeof(t_ver))))
		return (NULL);
	god->ver[god->q_ver++] = ptr;
	ptr->name = ft_strdup(name);
	if (!(create_struct(ptr->edg, sizeof(t_edg))))
		return (NULL);
	ptr->edg->owner = ptr;
	return (ptr);
}

void	*add_ver_in_edg(t_ver *v0, t_ver *v1)
{
	printf("%s\n", __func__);
	t_ver	**tmp;
	int		i;

	if (!(tmp = (t_ver**)malloc(sizeof(t_ver*) * ++(v0->edg->qlink))))
		return (NULL);
	i = -1;
	while (++i < v0->edg->qlink - 1)
		tmp[i] = v0->edg->ver[i];
	tmp[i] = v1;
	free(&v0->edg->ver);
	v0->edg->ver = tmp;

	if (!(tmp = (t_ver**)malloc(sizeof(t_ver*) * ++(v1->edg->qlink))))
		return (NULL);
	i = -1;
	while (++i < v1->edg->qlink - 1)
		tmp[i] = v1->edg->ver[i];
	tmp[i] = v0;
	free(v1->edg->ver);
	v1->edg->ver = tmp;

	return (v0->edg->ver);
}

void		print_god_vert(void)
{
	printf("%s\n", __func__);
	int i;

	i = -1;
	while (++i > god->q_ver)
		printf("%d\t->%s\n", i, god->ver[i]->name);
}

void	*link_vertices(void)
{
	printf("%s\n", __func__);
	char	*ver_one;
	char	*ver_two;

	printf("Please choose 2 vertices\n");
	if (0 >= get_next_line(0, &ver_one))
		return (NULL);
	if (0 >= get_next_line(0, &ver_two))
		return (NULL);
	while (ver_one[0] != '\0' || ver_two[0] != '\0')
	{
		add_ver_in_edg(god->ver[ft_atoi(ver_one)], god->ver[ft_atoi(ver_two)]);
		ft_strdel(&ver_one);
		ft_strdel(&ver_two);
		if (0 >= get_next_line(0, &ver_one))
			return (NULL);
		if (0 >= get_next_line(0, &ver_two))
			return (NULL);
	}
	return (god);
}

void	*first_init(void)
{
	printf("%s\n", __func__);
	char	*instruction;

	if (!(god = create_struct(god, sizeof(t_god))))
		return(NULL);
	if (!(god->ver = (t_ver**)malloc(sizeof(t_ver*) * TOTAL_VERTICES)))
		return (NULL);
	if (0 >= get_next_line(0, &instruction))
		return (NULL);
	while (instruction[0] != '\0')
	{
		create_vertice(instruction);
		ft_strdel(&instruction);
		if (0 >= get_next_line(0, &instruction))
			return (NULL);
	}
	return (god);
}

int		main(void)
{
	printf("%s\n", __func__);
	if (!(first_init()))
		return(-1);
	if (!(link_vertices()))
		return(-1);
	return (0);
}
