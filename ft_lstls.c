#include "ft_ls.h"

void ft_lstls(n_list *lst)
{
    while (lst)
    {
        ft_lss(lst->name);
        lst = lst->next;
    }
}