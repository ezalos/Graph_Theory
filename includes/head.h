/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   head.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 16:48:06 by ldevelle          #+#    #+#             */
/*   Updated: 2019/02/16 14:56:50 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include <stdio.h>
# include "../../libft/libft.h"

# define TOTAL_VERTICES 100

typedef struct			s_vertice
{
	char				*name;
	int					serial_nb;
	char				**attributes;
	struct s_edge		*edg;
}						t_ver;

typedef struct			s_edge
{
	struct s_vertice	*owner;
	int					qlink;
	char				**attributes;
	t_list				*ver;
}						t_edg;

typedef struct			s_god
{
	t_ver				**ver;
	int					q_ver;
	int					q_ver_at;
	t_edg				**edg;
	int					q_edg;
	int					q_edg_at;
}						t_god;

//INIT
t_god		*first_init(void);

//CREATE
void		*create_struct(void *ptr, size_t size);
t_ver		*create_vertice(t_god *god, char *name);

//LINK
void		*link_vertices(t_god *god);
void		add_vers_in_edgs(t_ver *v0, t_ver *v1);
void		add_ver_in_edg(t_ver *v0, t_ver *v1);

//PRINT
void		print_links(t_god *god, t_ver *v0);
void		print_god_vert(t_god *god);


#endif
