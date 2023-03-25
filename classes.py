
import pygame

# Struct that carries window data
class window_stuct():

	def __init__(self, width, height):

		self.width = width
		self.height = height
		self.window = pygame.display.set_mode((width, height))
		self.game_width = width
		self.game_height = height - 100

class background():

	def __init__(self, width, height, colour):

		self.surface = pygame.Surface((width, height))
		self.colour = self.surface.fill(pygame.Color(colour))

class game():

	def __init__(self, size, debug):

		self.row = size
		self.map_size = size * size
		self.generation = 1
		self.arena = [0x01] * self.map_size
		self.debug = debug