
#include "../includes/gol.h"

void	init_game(t_game *game)
{
	uint32_t	i;

	i = 0;
	srand(time(NULL));
	while (i < MAP_SIZE)
	{
		if (rand() % 100 < 10)
			game->map[i] = 0x01;
		else
			game->map[i] = 0x00;
		i++;
	}
	game->alive = true;
	game->round = 0;
}

void	print_generation(uint8_t *map, uint32_t round)
{
	ft_printf("size %d\n", SIZE);
	ft_printf("gene %d\n", round);
	uint32_t x = 0;
	while (x < MAP_SIZE)
	{
		if (map[x] & 0x01)
			ft_printf("x");
		else
			ft_printf(".");
		if ((x + 1) % SIZE == 0)
			ft_printf("\n");
		x++;
	}
	ft_printf("\n");
}