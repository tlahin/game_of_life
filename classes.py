
import pygame

# Struct that carries window data
class window_stuct():

	def __init__(self, width, height):

		self.width = width
		self.height = height
		self.window = pygame.display.set_mode((width, height))
		self.game_width = width
		self.game_height = height - 100
