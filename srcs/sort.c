/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkikuchi <kkikuchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 17:10:34 by kkikuchi          #+#    #+#             */
/*   Updated: 2020/12/04 20:45:57 by kkikuchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_mini_ls.h"

int				sort_ascii(char *a, char *b)
{
	if (ft_strcmp(a, b) < 0)
		return (1);
	return (0);
}

int				sort_time(char *a, char *b)
{
	struct stat as;
	struct stat bs;

	lstat(a, &as);
	lstat(b, &bs);
	if (as.st_mtimespec.tv_sec < bs.st_mtimespec.tv_sec)
	{
		return (0);
	}
	if (as.st_mtimespec.tv_sec == bs.st_mtimespec.tv_sec)
	{
		if (as.st_mtimespec.tv_nsec < bs.st_mtimespec.tv_nsec)
			return (0);
		else if (as.st_mtimespec.tv_nsec == bs.st_mtimespec.tv_nsec)
			return (sort_ascii(a, b));
	}
	return (1);
}

void			bubble_sort(char **array, int array_size)
{
	int			i;
	int			j;

	i = 0;
	while (i < array_size - 1)
	{
		j = i + 1;
		while (j < array_size)
		{
			if (sort_time(array[i], array[j]) == 1)
			{
				swap(&array[i], &array[j]);
			}
			j++;
		}
		i++;
	}
}

size_t			ft_strlen(const char *str)
{
	size_t		i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void			swap(char **a, char **b)
{
	char *temp;

	temp = *a;
	*a = *b;
	*b = temp;
}
