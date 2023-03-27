
#include "../includes/gol.h"

void	parse_seed(t_game *game, char **av)
{
	
}

void	init_gol(t_game *game, char **av)
{
	game->round = 1;
	game->alive = true;
	parse_seed(game, av);
}
