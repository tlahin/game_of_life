
#include "../includes/gol.h"

void	init_game(uint8_t *map)
{
	uint32_t i;

	i = 0;
	srand(time(NULL));
	while (i < MAP_SIZE)
	{
		if (rand() % 100 < 5)
			map[i] = 0x01;
		else
			map[i] = 0x00;
		i++;
	}
}

void	print_generation(uint8_t *map, uint32_t generation)
{
	uint32_t i;

	i = 0;
	ft_printf("size: %d\n", SIZE);
	ft_printf("gene: %d\n", generation);
	while (i < MAP_SIZE)
	{
		//ft_printf("\ni: %d m: %d ", i, map[i]);
		if (map[i] & 0x01)
			ft_printf("x");
		else
			ft_printf(".");
		if ((i + 1) % SIZE == 0)
			ft_printf("\n");
		i++;
	}
	ft_printf("\n");
}