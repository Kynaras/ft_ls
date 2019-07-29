/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stat.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keverett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 08:10:46 by keverett          #+#    #+#             */
/*   Updated: 2019/07/16 10:47:23 by keverett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>
#include <time.h>
#include <pwd.h>
#include <dirent.h>
int main(void)
{
	DIR *fd;
	struct stat sb;
	struct passwd *id;
	struct dirent *de;


	fd = opendir(".");

	de = readdir(fd);
		// printf("%d", fd-)
	if (stat("diread.c", &sb) != -1)
	{
		printf("%hu\n", sb.st_mode);
	}
	// if ((id = getpwuid(sb.st_uid)))
	// {
	// 	printf("%s\n", id->pw_name);
	// 	printf("%s\n", id->pw_passwd);
	// }	
	return (0);
}


