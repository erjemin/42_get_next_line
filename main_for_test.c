/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mretha <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/18 14:54:10 by mretha            #+#    #+#             */
/*   Updated: 2019/05/18 14:54:15 by mretha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "get_next_line.h"

int		main()
{
	char	filename1[] = "get_next_line.c";
	//char	filename2[] = "one_big_fat_line.txt";
	char	filename2[] = "get_next_line.h";
	int 	file1;
	int 	file2;
	int 	errcode1;
	int 	errcode2;
	char 	*str;

	if ((file1 = open(filename1, O_RDONLY)) == -1)
		return (file1);
	if ((file2 = open(filename2, O_RDONLY)) == -1)
		return (file2);
	printf("Hello, World! %d/%d\n", file1, file2);
	while (42)
	{
		errcode1 = get_next_line(file1, &str);
		if (errcode1 > 0)
			printf("\n1>>%03d(%d)>>\t%s", (int)ft_strlen(str), errcode1, str);
		errcode2 = get_next_line(file2, &str);
		if (errcode2 > 0)
			printf("\n2>>%03d(%d)>>\t%s", (int)ft_strlen(str), errcode2, str);
		if (errcode1 <= 0 && errcode2 <= 0)
			break ;
	}
	/*while (42)
	{
		errcode2 = get_next_line(file2, &str);
		if (errcode2 >= 0)
			printf("\n2>>%03d(%d)>>\t%s", (int)ft_strlen(str), errcode2, str);
		if (errcode2 <= 0)
			break ;
	}*/
	close(file1);
	close(file2);
	return (0);
}
