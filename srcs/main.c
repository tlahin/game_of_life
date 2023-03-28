
#include "../includes/gol.h"

int	main(int ac, char **av)
{
	t_game game;

	if (ac != 2)
	{
		print_usage();
		return (KO);
	}
	init_gol(&game, av);
	//print_generation(&game);
	while (game.alive == true)
		evolve(&game);
	return (OK);
}