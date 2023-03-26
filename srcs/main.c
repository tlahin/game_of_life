
#include "../includes/gol.h"

int	main(int ac, char **av)
{
	t_game game;

	init_gol(&game, ac, av);
	print_generation(&game);
	while (game.alive == true)
		evolve(&game);
	return (OK);
}