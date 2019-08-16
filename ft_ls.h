#ifndef FT_LS_H
#	define FT_LS_H

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
//# include <uuid/uuid.h>
# include <grp.h>
# include <time.h>
# include <unistd.h>
#include <sys/xattr.h>

typedef struct name_list
{
	char *name;
	char *path;
	struct stat sb;
	struct name_list *next;
} n_list;

typedef	struct flag_list
{
	unsigned int 	recursive : 1;
	unsigned int 	reverse : 1;
	unsigned int 	time : 1;
	unsigned int 	hidden : 1;
	unsigned int	list : 1;
} f_list;

typedef struct var_list
{
	DIR				*dr;
	struct dirent	*de;
	n_list			*lst;
    n_list			*dirs;
    n_list			*tmp;
    char			*str;
} v_list;

void	ft_regcomp(n_list *a, n_list *b, n_list **result, f_list flags);
int		ft_readflag(int argc, char **argv, f_list *flags);
f_list	*ft_checkflags(int argc, char **argv, f_list *flags);
void 	ft_lss(char *path, f_list flags);
void 	ft_mergesort(n_list **lst, f_list flags);
n_list 	*ls_lstnew(char *name, char *path);
void 	ls_lstadd(n_list *head, n_list *new);
n_list 	*ft_diread(char *path);
n_list	*ft_makelst(DIR *dr);
void	ft_printlst(n_list *lst, f_list flags);
n_list 	*ft_readdir(char *path, f_list flags);
void	ft_flagset(f_list *flags);
void	ft_only_names(int argc, char **argv);
int		ft_flagcount(f_list *flags);
void 	ft_dellst(n_list *lst);
char	ft_finderror(int argc, char **argv);
n_list	*ft_arglst(int argc, char **argv, int i, int type);
void	ft_filestats(n_list *lst, struct stat sb, char *path);
void	ft_timesplit(char *str);
n_list	*sortlist(n_list *a, n_list *b, f_list flags);
void	ft_timecmp(n_list *a, n_list *b, n_list **result, f_list flags);
size_t	ft_findsize(n_list *lst, int type);
void	ft_structstat(n_list *lst);
size_t 	ft_numsize(long long number);
size_t	ft_findtotsize(n_list *lst, int type);
size_t 	ft_findlen(char *str);
void 	ft_linkname(char *path);
int		ft_attr(char *path);

#endif