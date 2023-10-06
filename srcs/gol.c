
#include "gol.h"

uint8_t	calculate_friends(uint8_t *map, uint32_t i)
{
	int32_t 	north, east, south, west;
	uint8_t		friends = 0;

	north = (i < SIZE) ? (SIZE * (SIZE - 1)) : -SIZE;
	east = (i % SIZE == SIZE - 1) ? -(SIZE - 1) : 1;
	south = (i / SIZE == SIZE - 1) ? -(SIZE * (SIZE - 1)) : SIZE;
	west = (i % SIZE == 0) ? SIZE - 1 : - 1;
	friends += map[i + north] & 0x1111;
	friends += map[i + east] & 0x01;
	friends += map[i + south] & 0x01;
	friends += map[i + west] & 0x01;
	friends += map[i + (north + east)] & 0x01;
	friends += map[i + (south + east)] & 0x01;
	friends += map[i + (south + west)] & 0x01;
	friends += map[i + (north + west)] & 0x01;
	return (friends);
}

void	evolve(uint8_t *map)
{
	uint32_t	i = 0;
	uint8_t		*cpy_map;
	uint8_t		friends;

	cpy_map = (uint8_t *)malloc(sizeof(uint8_t) * MAP_SIZE + 1);
	cpy_map[MAP_SIZE] = '\0';
	ft_memcpy(cpy_map, map, MAP_SIZE);
	while (i++ < MAP_SIZE)
	{
		friends = calculate_friends(map, i);
		//ft_printf("i: %d v: %d f: %d\n", i, cpy_map[i], friends);
		if (cpy_map[i] & 1) // is alive
		{
			if (friends < 2 || friends > 3)
			{
				map[i] -= 0x01;
			} 
		}
		else // is dead
		{
			if (friends == 3)
			{
				map[i] += 0x01;
			}
		}
	}
}

void	game(uint8_t *map)
{
	bool		running = true;
	uint32_t	generation = 1;

	while (running)
	{
		evolve(map);
		print_generation(map, generation);
		generation++;
		if (generation > 100000)
			running = false;
	}
}