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
	struct dirent *ptr;
	struct name_list *next;
} n_list;

void 	ft_mergesort(n_list **lst);
n_list 	*ls_lstnew(struct dirent *ptr);
void 	ls_lstadd(n_list *head, n_list *new);
n_list 	*diread(char *path);
n_list	*ft_makelst(DIR *dr);

#endif
