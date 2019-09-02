ft_bubble()
{
	struct stat sb;
	struct stat sb1;
	t_ls		*ptr;
	int			i;
	char		*tp;

	ptr = *head;
	i = -1;
	if (flags[5] == '1')
		i = 1;
	while (ptr->next != NULL)
	{
		stat(ptr->directory, &sb);
		stat(ptr->next->directory, &sb1);
		if (((i * ((int)sb.st_mtimespec.tv_sec - (int)sb1.st_mtimespec.tv_sec)) > 0) || (((i * ((int)sb.st_mtimespec.tv_sec - (int)sb1.st_mtimespec.tv_sec) == 0
							&& (i * ((int)sb.st_mtimespec.tv_nsec - (int)sb1.st_mtimespec.tv_nsec)) > 0))))
		{
			tp = ptr->directory;
			ptr->directory = ptr->next->directory;
			ptr->next->directory = tp;
			ptr = *head;
		}
		else
			ptr = ptr->next;
	}
}
