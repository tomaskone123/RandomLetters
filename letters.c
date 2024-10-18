/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   letters.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomas <tomas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 21:47:07 by tomas             #+#    #+#             */
/*   Updated: 2024/10/19 00:24:15 by tomas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "letters.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>


void swap(char *a, char *b)
{
	char temp = *a;
	*a = *b;
	*b = temp;
}

void shuffle(char *array, size_t n)
{
	if (n > 1)
	{
		for (size_t i = 0; i < n - 1; i++)
		{
			size_t j = i + rand() / (RAND_MAX / (n - i) + 1);
			if (j < n)
				swap(&array[i], &array[j]);
		}
	}
}

void randomletters(char input[])
{
	char letters[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ ";
	char *output;
	int c;
	int index;

	c = 0;
	index = 0;
	output = malloc((ft_strlen(input) + 1) * sizeof(char));
	if (!output)
		return;
	size_t n = ft_strlen(letters);

	srand(time(NULL));
	shuffle(letters, n);
	ft_printf("Searching the letters.....\n");
	while (input[c])
	{
		while (letters[index])
		{
			output[c + 1] = '\0';
			usleep(20000);
			if (letters[index] == input[c])
			{
				output[c] = letters[index];
				break;
			}
			if (c >= 1)
				printf("%s", output);
			printf("%c\n", letters[index]);
			index++;
		}
		index = 0;
		c++;
	}
	ft_printf("%s\n", output);
	ft_printf("Found your input in the alphabet :^)");
	free(output);
}

int main(int argc, char *argv[])
{
	if (!check_input(argv[1], argc))
		return (1);
	randomletters(argv[1]);

	return (1);
}
