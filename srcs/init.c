
#include "../includes/gol.h"

void	parse_seed(t_game *game, char *file)
{
	char	*seed[MAP_SIZE];
	int		fd;
	int		ret;

	fd = open(file, O_RDONLY);
	ret = read(fd, &seed, MAP_SIZE);
	if (ret > 0)
		ft_printf("%s\n", seed);
	close(fd);
	(void)game;
}

void	init_gol(t_game *game, char **av)
{
	game->round = 1;
	game->alive = true;
	parse_seed(game, av[1]);
}
