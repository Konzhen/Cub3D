/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbutte <jbutte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 18:44:34 by jbutte            #+#    #+#             */
/*   Updated: 2023/07/22 18:44:36 by jbutte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libcub.h"

int	main(int argc, char **argv)
{
	char	**tab;

	if (check_argc(argc, 2, 2))
		return (1);
	tab = checker(argv[1]);
	if (!tab)
		printf("false\n");
}
