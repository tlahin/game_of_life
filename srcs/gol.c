
#include "../includes/gol.h"

void	set_friends(t_game *game, uint32_t i, uint32_t alive)
{

	int32_t north, east, south, west;

	north = (i < SIZE) ? (SIZE * (SIZE - 1)) : -SIZE;
	east = (i % SIZE == SIZE - 1) ? -(SIZE - 1) : 1;
	south = (i / SIZE == SIZE - 1) ? -(SIZE * (SIZE - 1)) : SIZE;
	west = (i % SIZE == 0) ? SIZE - 1 : - 1;

	if (!alive)
	{
		game->map[i + north] -= 0x02;
		game->map[i + east] -= 0x02;
		game->map[i + south] -= 0x02;
		game->map[i + west] -= 0x02;
		game->map[i + (north + east)] -= 0x02;
		game->map[i + (south + east)] -= 0x02;
		game->map[i + (south + west)] -= 0x02;
		game->map[i + (north + west)] -= 0x02;
	}
	else
	{
		game->map[i + north] += 0x02;
		game->map[i + east] += 0x02;
		game->map[i + south] += 0x02;
		game->map[i + west] += 0x02;
		game->map[i + (north + east)] += 0x02;
		game->map[i + (south + east)] += 0x02;
		game->map[i + (south + west)] += 0x02;
		game->map[i + (north + west)] += 0x02;
	}
}

void	toggle_cell(t_game *game, uint32_t i)
{
	uint32_t alive = is_alive(game, i);
	if (alive)
		game->map[i] = 0x01;
	else
		game->map[i] = 0x00;
	set_friends(game, i, alive);
}

uint32_t	is_alive(t_game *game, uint32_t i)
{
	return (game->map[i] & 0x01);
}

void	gol(t_game *game)
{
	uint32_t	i;
	uint32_t	friends;

	i = 0;
	while (game->alive == true)
	{
		while (i < MAP_SIZE)
		{
			friends = game->map[i] >> 1;
			if (is_alive(game, i))
			{
				if (friends < 2 || friends > 3)
					toggle_cell(game, i);
			}
			else
			{
				if (friends == 3)
					toggle_cell(game, i);
			}
			i++;
		}
		game->round++;
		print_generation(game->map, game->round);
		if (game->round > 2)
			game->alive = false;
	}
}