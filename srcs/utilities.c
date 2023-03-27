
#include "../includes/gol.h"

void	print_usage(void)
{
	ft_printf("\nusage:\n\t./game [seed.txt]\n\n");
}

void	print_generation(t_game *game)
{
	ft_printf("size %d\n", SIZE);
	ft_printf("gene %d\n", game->round);
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