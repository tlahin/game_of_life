
import pygame
import sys
import time

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

def return_next_line(x):

	for _ in range(x):
		sys.stdin.readline()
	str = sys.stdin.readline()
	return str

running = True

while running:

	for event in pygame.event.get():
		if event.type == pygame.QUIT:
			running = False
		if event.type == pygame.KEYDOWN:
			if event.key == pygame.K_SPACE:
				print("Pause")
				pause()
				print("Continue")
			if event.key == pygame.K_ESCAPE:
				running = False


	pygame.display.flip()

	size = return_next_line(0)
	size = int(size[5:(len(size) - 1)])
	
	generation = return_next_line(0)
	generation = int(generation[5:len(generation) - 1])
	
	cell_size = int(window_data.width / size)

	map_size = size * size

	row = 0
	while row < size:
		line = return_next_line(0)
		col = 0
		while col < len(line) - 1:
			if line[col] == "x":
				pygame.draw.rect(window_data.window, "Black", pygame.Rect(col * cell_size, row * cell_size, cell_size, cell_size))
			else:
				pygame.draw.rect(window_data.window, "White", pygame.Rect(col * cell_size, row * cell_size, cell_size, cell_size))
			col += 1
		row += 1
	
	return_next_line(0)

	#break