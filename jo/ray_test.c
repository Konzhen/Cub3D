/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_test.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dafranco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 15:55:20 by dafranco          #+#    #+#             */
/*   Updated: 2023/07/05 15:55:56 by dafranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	int i = 0;
	int j = 0;
	static char grid[90][91];

	while(i < 90)
	{
		while(j < 91)
		{
			grid[i][j] = '#';
			j++;
			if(j == 90 && i <= 90)
			{
				grid[i][j] = '\n';
				j++;
				grid[i][j] = '\0';
			}
		}
		j = 0;
		i++;
	}
	i = 44;
	j = 44;
	grid[i][j] = '@';
	while (i < 90)
	{
		i++;
		grid[i][j] = ',';
	}
	i = 44;
	while (j < 89)
	{
		j++;
		i++;
		grid[i][j] = ',';
	}
	i = 44;
	j = 44;
	while (j < 68)
	{
		i++;
		grid[i][j] = '.';
		i++;
		j++;
		grid[i][j] = '.';
	}
	i = 44;
	j = 44;
	while (i < 90)
	{
		i++;
		grid[i][j] = ',';
		i++;
		grid[i][j] = ',';
		i++;
		grid[i][j] = ',';
		j++;
		i++;
		grid[i][j] = ',';
	}
	i = 44;
	j = 44;
	while (j < 90)
	{
		i++;
		grid[i][j] = ',';
		j++;
		i++;
		grid[i][j] = ',';
		j++;
		i++;
		grid[i][j] = ',';
	}
	i = 0;
	printf("%s", grid[i]);
	return (0);
}
