/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   head.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 16:48:06 by ldevelle          #+#    #+#             */
/*   Updated: 2019/02/15 13:51:45 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include <stdio.h>
# include "../../libft/libft.h"

# define TOTAL_VERTICES 10

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
	struct s_vertice	**ver;
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

static t_god			*god;

#endif
