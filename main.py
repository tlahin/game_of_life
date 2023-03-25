
import pygame
import sys

import classes

pygame.init()

# Window init
pygame.display.set_caption("Epic Game")

# Window struct, carries width, height and the window surface
window_data = classes.window_stuct(1000, 1000)

# Main menu background
bg_main_menu = classes.background(window_data.width, window_data.height, 'aquamarine2')

# input row/col size
game_data = classes.game(20)

running = True

while running:

	pygame.display.flip()

	# Main menu background
	window_data.window.blit(bg_main_menu.surface, (0, 0))

	# Quits the program if you close the window
	for event in pygame.event.get():
		if event.type == pygame.QUIT:
			running = False
			pygame.quit()

pygame.quit()