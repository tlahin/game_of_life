
#include "gol.h"

int	main(void)
{
	uint8_t *map;

	map = (uint8_t *)malloc(sizeof(uint8_t) * MAP_SIZE + 1);
	map[MAP_SIZE] = '\0';
	init_game(map);
	game(map);
	return (1);
}