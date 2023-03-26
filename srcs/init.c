
#include "../includes/gol.h"

void	init_gol(t_game *game, int ac, char **av)
{
	game->round = 1;
	game->alive = true;
	if (ac >= 1)
	{
		int i = 1;
		int x = 0;
		while (x < MAP_SIZE)
		{
			if (ac > 1)
			{
				if (x == ft_atoi(av[i]) - 1)
				{
					game->map[x] = 0x01;
					if (i < ac - 1)
						i++;
				}
			}
			else
				game->map[x] = 0x00;
			x++;
		}
	}
}
