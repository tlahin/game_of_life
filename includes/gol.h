
#ifndef GOL_H
# define GOL_H

# include "../libft/includes/libft.h"
# include "../libft/includes/get_next_line.h"
# include <fcntl.h>
# include <time.h>

# define SIZE 200
# define MAP_SIZE SIZE * SIZE


int			main(void);
void		init_game(uint8_t *map);
void		print_generation(uint8_t *map, uint32_t generation);
void		game(uint8_t *map);
void		evolve(uint8_t *map);
uint8_t		calculate_friends(uint8_t *map, uint32_t i);

#endif