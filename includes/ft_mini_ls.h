/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mini_ls.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkikuchi <kkikuchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 17:13:17 by kkikuchi          #+#    #+#             */
/*   Updated: 2020/12/04 21:02:52 by kkikuchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MINI_LS_H
# define FT_MINI_LS_H

# include <dirent.h>
# include <string.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <time.h>
# include <errno.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

int		sort_ascii(char *a, char *b);
void	bubble_sort(char **array, int array_size);
int		sort_ascii(char *a, char *b);
int		main(int argc, char **argv);
void	swap(char **a, char **b);
int		ft_strcmp(const char *s1, const char *s2);
size_t	ft_strlen(const char *str);

#endif
