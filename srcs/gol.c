
#include "../includes/gol.h"

static bool	is_alive(t_game *game, uint32_t index)
{
	return (game->map[index] & 0x01);
}

static void	set_neighbours(t_game *game, uint32_t index, bool kill)
{
	int north, east, south, west;

	north = (index < SIZE) ? (SIZE * (SIZE - 1)) : -SIZE;
	east = (index % SIZE == SIZE - 1) ? -(SIZE - 1) : 1;
	south = (index / SIZE == SIZE - 1) ? -(SIZE * (SIZE - 1)) : SIZE;
	west = (index % SIZE == 0) ? SIZE - 1 : - 1;

	if (kill)
	{
		game->map[index + north] -= 0x02;
		game->map[index + east] -= 0x02;
		game->map[index + south] -= 0x02;
		game->map[index + west] -= 0x02;
		game->map[index + (north + east)] -= 0x02;
		game->map[index + (south + east)] -= 0x02;
		game->map[index + (south + west)] -= 0x02;
		game->map[index + (north + west)] -= 0x02;
	}
	else
	{
		game->map[index + north] += 0x02;
		game->map[index + east] += 0x02;
		game->map[index + south] += 0x02;
		game->map[index + west] += 0x02;
		game->map[index + (north + east)] += 0x02;
		game->map[index + (south + east)] += 0x02;
		game->map[index + (south + west)] += 0x02;
		game->map[index + (north + west)] += 0x02;
	}
}

static void toggle_cell(t_game *game, uint32_t index)
{
	bool	kill = is_alive(game, index);
	game->map[index] ^= 0x01;
	set_neighbours(game, index, kill);
}

void	evolve(t_game *game)
{
	uint32_t	index = 0;
	uint8_t		map_copy[MAP_SIZE];
	uint32_t	neighbours;

	ft_memcpy(map_copy, game->map, MAP_SIZE);
	while (index < MAP_SIZE)
	{
		if (map_copy[index])
		{
			neighbours = map_copy[index] >> 1;
			if (map_copy[index] & 0x01)
			{
				if (neighbours < 2 || neighbours > 3)
					toggle_cell(game, index);
			}
			else
			{
				if (neighbours == 3)
					toggle_cell(game, index);
			}
		}
		index++;
	}
	//print_generation(game);
	game->round++;
	if (game->round >= 2)
		game->alive = false;
}