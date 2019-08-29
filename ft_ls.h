/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keverett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 11:49:20 by keverett          #+#    #+#             */
/*   Updated: 2019/08/29 11:49:23 by keverett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include <sys/types.h>
# include <sys/stat.h>
# include <dirent.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/errno.h>
# include <string.h>
# include "libft/libft.h"
# include <pwd.h>
# include <grp.h>
# include <time.h>
# include <unistd.h>
# include <sys/xattr.h>

typedef struct	s_size_list
{
	long long	unamesize;
	long long	gnamesize;
	long long	linksize;
	long long	size;
}				t_s_list;

typedef struct	s_name_list
{
	char				*name;
	char				*path;
	unsigned int		error : 1;
	struct stat			sb;
	struct s_name_list	*next;
	struct s_name_list	*last;
}				t_n_list;

typedef struct	s_flag_list
{
	unsigned int recursive : 1;
	unsigned int reverse : 1;
	unsigned int time : 1;
	unsigned int hidden : 1;
	unsigned int list : 1;
	unsigned int semihidden : 1;
	unsigned int colours : 1;
	unsigned int groups : 1;
	unsigned int unsorted : 1;
	unsigned int users : 1;
}				t_f_list;

typedef struct	s_var_list
{
	DIR				*dr;
	struct dirent	*de;
	t_n_list		*lst;
	t_n_list		*dirs;
	t_n_list		*tmp;
	char			*str;
}				t_v_list;

typedef struct	s_vars_list
{
	char		error;
	t_n_list	*lst;
	t_f_list	flags;
	t_n_list	*dirs;
	int			i;
	int			j;
}				t_vs_list;

void			ft_regcomp(t_n_list *a, t_n_list *b, t_n_list **result,
t_f_list *flags);
int				ft_readflag(int argc, char **argv, t_f_list *flags);
t_f_list		*ft_checkflags(int argc, char **argv, t_f_list *flags);
void			ft_lss(char *path, t_f_list *flags);
void			ft_mergesort(t_n_list **lst, t_f_list *flags);
t_n_list		*ls_lstnew(char *name, char *path);
void			ls_lstadd(t_n_list *head, t_n_list *new);
t_n_list		*ft_makelst(DIR *dr);
void			ft_printlst(t_n_list *lst, t_f_list *flags);
t_n_list		*ft_readdir(char *path, t_f_list *flags);
void			ft_flagset(t_f_list *flags);
void			ft_only_names(int argc, char **argv);
int				ft_flagcount(t_f_list *flags);
void			ft_dellst(t_n_list *lst);
char			ft_finderror(int argc, char **argv);
t_n_list		*ft_arglst(int argc, char **argv, int i, int type);
void			ft_filestats(struct stat sb, char *path, t_s_list totals,
t_f_list *flags);
void			ft_timesplit(char *str, struct stat *sb);
t_n_list		*sortlist(t_n_list *a, t_n_list *b, t_f_list *flags);
void			ft_timecmp(t_n_list *a, t_n_list *b, t_n_list **result,
t_f_list *flags);
size_t			ft_findsize(t_n_list *lst, int type);
void			ft_structstat(t_n_list *lst);
size_t			ft_numsize(long long number);
size_t			ft_findtotsize(t_n_list *lst, int type);
size_t			ft_findlen(char *str);
void			ft_linkname(char *path);
int				ft_attr(char *path);
t_s_list		ft_totalsizelst(t_n_list *lst);
void			ft_grps(t_f_list *flags, struct stat *sb, char *path,
t_s_list *totals);
void			ft_users(t_f_list *flags, struct stat *sb, char *path,
t_s_list *totals);
void			ft_size(struct stat *sb,
t_s_list *totals);
void			ft_colours(t_n_list *lst);
#endif
