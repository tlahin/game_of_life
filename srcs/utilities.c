
#include "../includes/gol.h"

void	print_generation(t_game *game)
{
	ft_printf("row %d\n", SIZE);
	ft_printf("gen %d\n", game->round);
	int x = 0;
	while (x < MAP_SIZE)
	{
		if (game->map[x] & 0x01)
			ft_printf("X");
		else
			ft_printf("O");
		if ((x + 1) % SIZE == 0)
			ft_printf("\n");
		x++;
	}
	ft_printf("\n");
}