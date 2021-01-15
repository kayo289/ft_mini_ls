/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mini_ls.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkikuchi <kkikuchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 18:16:09 by kkikuchi          #+#    #+#             */
/*   Updated: 2020/12/05 16:02:52 by kkikuchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_mini_ls.h"
#include <errno.h>

static char **store_filename(char **filename, char *new_filename, int c)
{
	char **tmp;
	int i;

	i = 0;
	if (!(tmp = malloc(sizeof(char *) * (c + 1))))
	{
		free(filename);
		return (NULL);
	}
	while (i < c)
	{
		tmp[i] = filename[i];
		i++;
	}
	int len = ft_strlen(new_filename);
	tmp[i] = (char *)malloc(sizeof(char) * (len + 1));
	int j;
	for (j = 0; j < len; j++)
		tmp[i][j] = new_filename[j];
	tmp[i][j] = '\0';
	return (tmp);
}

int ft_strcmp(const char *s1, const char *s2)
{
	size_t i;

	i = 0;
	while ((s1[i] == s2[i]) && s1[i] && s2[i])
		i++;
	if (s1[i] == s2[i])
		return (0);
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

static void put_filename(char **filename, int c)
{
	int i;

	i = 0;
	while (i < c)
	{
		write(1, filename[i], ft_strlen(filename[i]));
		write(1, "\n", 1);
		free(filename[i]);
		i++;
	}
}

int error(DIR **dir, int argc)
{
	if (argc > 1)
	{
		write(2, "Prohibited to use command line arguments\n", 41);
		return (1);
	}
	if ((*dir = opendir("./")) == NULL)
	{
		perror("./");
		return (1);
	}
	return (0);
}

int main(int argc, char **argv)
{
	DIR *dir;
	struct dirent *dent;
	char **files;
	int c;

	c = 0;
	if (error(&dir, argc) == 1)
		return (1);
	while ((dent = readdir(dir)) != NULL)
	{
		if (dent->d_name[0] == '.')
			continue;
		if (!(files = store_filename(files, dent->d_name, c++)))
			return (1);
	}
	bubble_sort(files, c);
	put_filename(files, c);
	closedir(dir);
	return (0);
}
