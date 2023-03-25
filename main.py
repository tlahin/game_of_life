
import pygame

import classes
import game
import sys

pygame.init()

# Window init
pygame.display.set_caption("Epic Game")

# Window struct, carries width, height and the window surface
window_data = classes.window_stuct(1300, 800)

# Main menu background
bg_main_menu = classes.background(window_data.width, window_data.height, 'aquamarine2')

# input row/col size
debug = False
if len(sys.argv) == 2:
	if sys.argv[1] == '-b':
		debug = True
game_data = classes.game(20, debug)

running = True

while running:

	pygame.display.flip()

	# Main menu background
	window_data.window.blit(bg_main_menu.surface, (0, 0))

	# Game loop
	game.evolve(game_data)
	running = False

	# Quits the program if you close the window
	for event in pygame.event.get():
		if event.type == pygame.QUIT:
			running = False
			pygame.quit()

pygame.quit()