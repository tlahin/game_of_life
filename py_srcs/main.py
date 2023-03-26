
import pygame
import sys

import classes

pygame.init()

# Window init
pygame.display.set_caption("Epic Game")

# Window struct, carries width, height and the window surface
window_data = classes.window_stuct(800, 800)

# Main menu background
bg_main_menu = classes.background(window_data.width, window_data.height, 'aquamarine2')


def pause():

	paused = True

	while paused:
		for event in pygame.event.get():
			if event.type == pygame.QUIT:
				return 1
			if event.type == pygame.KEYDOWN:
				if event.key == pygame.K_SPACE:
					paused = False
					return False
	return True

running = True

while running:

	for event in pygame.event.get():
		if event.type == pygame.QUIT:
			running = False
		if event.type == pygame.KEYDOWN:
			if event.key == pygame.K_SPACE:
				pause()
				print("Continue")
			if event.key == pygame.K_ESCAPE:
				running = False

	
