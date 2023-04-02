
#ifndef GOL_H
# define GOL_H

# include "../libft/includes/libft.h"
# include "../libft/includes/get_next_line.h"
# include <fcntl.h>
# include <time.h>

# define SIZE 20
# define MAP_SIZE SIZE * SIZE

typedef struct s_game t_game;

struct s_game
{
	uint8_t		map[MAP_SIZE];
	uint32_t	round;
	bool		alive;
};

int			main(void);
void		print_generation(uint8_t *map, uint32_t round);
void		init_game(t_game *game);
void		gol(t_game *game);

uint32_t	is_alive(t_game *game, uint32_t i);
void		toggle_cell(t_game *game, uint32_t i);
void		set_friends(t_game *game, uint32_t i, uint32_t alive);
#endif