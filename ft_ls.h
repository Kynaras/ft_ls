#ifndef FT_LS_H
#	define FT_LS_H

# include <sys/types.h>
# include <sys/stat.h>
# include <dirent.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <stdio.h> 
# include <sys/errno.h>
# include <string.h>
# include "libft/libft.h" 

typedef struct name_list
{
	char *name;
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

void	ft_readflag(int argc, char **argv, f_list *flags);
f_list	*ft_checkflags(int argc, char **argv, f_list *flags);
void 	ft_lss(char *path, f_list flags);
void 	ft_mergesort(n_list **lst);
n_list 	*ls_lstnew(char *name);
void 	ls_lstadd(n_list *head, n_list *new);
n_list 	*ft_diread(char *path);
n_list	*ft_makelst(DIR *dr);
void	ft_printlst(n_list *lst, f_list flags);
n_list 	*ft_readdir(char *path, f_list flags);
void	ft_flagset(f_list *flags);
void	ft_only_names(int argc, char **argv);
int		ft_flagcount(f_list *flags);

#endif