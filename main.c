/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artmende <artmende@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 11:36:58 by artmende          #+#    #+#             */
/*   Updated: 2021/09/17 18:07:18 by artmende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	Simply compile this main.c file.
**
**	Executing the program without any argument will display all numbers
**	between 0 and 19 in a pseudorandom order.
**
**	As first argument, you can specify how many numbers you want to display.
**	All numbers from 0 up to the number specified will be displayed in a
**	pseudorandom order.
**
**	As a second argument, you can type a hyphen '-'.
**	It will then display as many numbers as specified in the first argument, in
**	the same range, but some numbers might be negative (around 38%).
**
**	In all cases, there will be no repetition in the numbers displayed.
**
**	Enjoy !
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <math.h>

int	main(int argc, char **argv)
{
	int	quantity_of_nbr;
	int	*nbr_array;
	int	current_nbr;
	int	i;
	int	j;

	if (argc > 1)
		quantity_of_nbr = atoi(argv[1]);
	else
		quantity_of_nbr = 20;
	nbr_array = malloc(sizeof(int) * quantity_of_nbr);
	if (!nbr_array)
		return (0);
	srand(time(NULL));
	i = 0;
	while (i < quantity_of_nbr)
	{
		if (argc > 2 && argv[2][0] == '-')
			current_nbr = pow(-1, rand()) * (rand() % quantity_of_nbr);
		else
			current_nbr = rand() % quantity_of_nbr;
		j = 0;
		while (j < i)
		{
			if (current_nbr == nbr_array[j])
			{
				current_nbr = rand() % quantity_of_nbr;
				j = 0;
			}
			else
				j++;
		}
			nbr_array[i] = current_nbr;
		i++;
	}
	while (i)
	{
		printf("%d ", nbr_array[i - 1]);
		i--;
	}
	printf("\n");
	free(nbr_array);
	return (0);
}
