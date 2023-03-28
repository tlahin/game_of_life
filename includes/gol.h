
#ifndef GOL_H
# define GOL_H

# include "../libft/libft.h"
# include "../libft/get_next_line.h"
# include <fcntl.h>

# define OK 1
# define KO -1

# define SIZE 20
# define MAP_SIZE SIZE * SIZE

typedef struct s_game t_game;

/*
	cell is a 8bit variable
	where bits 4-7 represent the neigbours
	8th bit represents state of current cell 
*/
struct s_game
{
	uint8_t		map[MAP_SIZE];
	uint32_t	round;
	bool		alive;
};

int		main(int ac, char **av);
void	init_gol(t_game *game, char **av);
void	evolve(t_game *game);

//utilities
void	print_generation(t_game *game);
void	print_usage(void);

#endif