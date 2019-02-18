/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 14:17:21 by ldevelle          #+#    #+#             */
/*   Updated: 2019/02/16 19:18:23 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/head.h"

void	*create_struct(void *ptr, size_t size)
{
	printf("%s\n", __func__);
	if (!(ptr = malloc(size)))
		return (NULL);
	ft_bzero((char*)ptr, size);
	printf("done\n");
	return(ptr);
}

t_ver	*create_vertice(t_god *god, char *name)
{
	printf("%s\n", __func__);
	t_ver	*ptr;

	ptr = NULL;


	if (!(ptr = (t_ver*)malloc(sizeof(t_ver))))
		return (NULL);
	ft_bzero((char*)ptr, sizeof(t_ver));
/*	if (!(ptr = create_struct(ptr, sizeof(t_ver))))
		return (NULL);*/
	ptr->serial_nb = god->q_ver;
	god->ver[god->q_ver++] = ptr;
	printf("strdup\n");
	ptr->name = ft_strdup(name);

	if (!(ptr->edg = (t_edg*)malloc(sizeof(t_edg))))
		return (NULL);
	ft_bzero(ptr->edg, sizeof(t_edg));

/*	if (!(create_struct(ptr->edg, sizeof(t_edg))))
		return (NULL);*/
	ptr->edg->owner = ptr;
	printf("%p|->%s[%d]\n", ptr, ptr->name, ptr->serial_nb);
	return (ptr);
}
