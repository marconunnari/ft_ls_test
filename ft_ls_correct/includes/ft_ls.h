/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguiulfo <gguiulfo@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/20 15:01:04 by gguiulfo          #+#    #+#             */
/*   Updated: 2017/05/03 23:07:44 by gguiulfo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include <libft.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <pwd.h>
# include <grp.h>
# include <uuid/uuid.h>
# include <dirent.h>
# include <errno.h>
# include <time.h>
# include <sys/xattr.h>
# include <limits.h>

typedef struct		s_file
{
	char			*name;
	char			*path;
	struct stat		statbuf;
	struct timespec	cmptime;
}					t_file;

enum				e_lsact
{
	LS_CRTE,
	LS_PRNT,
	LS_KILL
};

enum				e_lsopts
{
	OPT_l = 0x1,
	OPT_R = 0x2,
	OPT_a = 0x4,
	OPT_r = 0x8,
	OPT_t = 0x10,
	OPT_S = 0x20,
	OPT_T = 0x40,
	OPT_o = 0x80,
	OPT_g = 0x100,
	OPT_A = 0x200,
	OPT_f = 0x400,
	OPT_d = 0x800,
	OPT_c = 0x1000,
	OPT_u = 0x2000,
	OPT_U = 0x4000
};

/*
** Main Functions
*/

int					ls_getopts(char *str);
int					ls_print_dir(char *path);
int					ls_args(int i, int argc, char **argv);
void				ls_file_l(t_file *file, int *padding, char *name);
void				ls_handle_all(t_dnarr **naf, t_dnarr **files,
										t_dnarr **dirs, int act);
void				ls_sort(t_dnarr *files);

/*
** Error Handling
*/

int					ls_ftsopen(t_dnarr *dirs, t_dnarr *files, t_dnarr *naf);
void				ls_naf_handle(t_dnarr *naf);

/*
** LS Utils
*/

char				*ls_pathname(char *path);
void				ls_print_link(char *path);
void				ls_free_pn(t_dnarr *files);
void				ls_padding_l(int *padding, struct stat statbuf);

#endif
