
import pygame

# Returns True if cell is alive False if not
def is_alive(game_data, i):

	if game_data.arena[i] & 0x01:
		return True
	return False

# Toggles cell alive/dead
def toggle_cell(game_data, i):

	kill = is_alive(game_data, i)
	game_data.arena[i] ^= 0x01
	set_neighbours(game_data, i, kill)

def set_neighbours(game_data, i, kill):

	# calculate north pos relative to i
	if i < game_data.row == 0:
		north = (game_data.row * (game_data.row - 1))
	else:
		north = -game_data.row

	# calculate east pos relative to i
	if i % game_data.row == game_data.row - 1:
		east = (game_data.row - 1) * -1
	else:
		east = 1
	
	# calculate south pos relative to i
	if int(i / game_data.row) == game_data.row - 1:
		south = -(game_data.row * (game_data.row - 1))
	else:
		south = game_data.row

	# calculate west pos relative to i
	if i % game_data.row == 0:
		west = game_data.row - 1
	else:
		west = -1
	
	# debug printing
	if game_data.debug == True:

		print((north + west) + i, north + i, (north + east) + i)
		print(west + i, i, east + i)
		print((south + west) + i, south + i, (south + east) + i)
		print("\n")

	if kill == True:
		game_data.arena[i + north] -= 0x02
		game_data.arena[i + east] -= 0x02
		game_data.arena[i + south] -= 0x02
		game_data.arena[i + west] -= 0x02
		game_data.arena[i + (north + east)] -= 0x02
		game_data.arena[i + (north + west)] -= 0x02
		game_data.arena[i + (south + east)] -= 0x02
		game_data.arena[i + (south + west)] -= 0x02
	else:
		game_data.arena[i + north] += 0x02
		game_data.arena[i + east] += 0x02
		game_data.arena[i + south] += 0x02
		game_data.arena[i + west] += 0x02
		game_data.arena[i + (north + east)] += 0x02
		game_data.arena[i + (north + west)] += 0x02
		game_data.arena[i + (south + east)] += 0x02
		game_data.arena[i + (south + west)] += 0x02

def evolve(game_data):
	
	i = 0
	while i < game_data.map_size:

		#print(i, arena[i])
		# Check if cell is alive
		if is_alive(game_data, i):
	
			# get amount of friends by bitshifting it right by 1
			friends = game_data.arena[i] >> 1

			if game_data.arena[i] < 2 or game_data.arena[i] > 3:
				toggle_cell(game_data, i)
			
			else:
				if friends == 3:
					toggle_cell(game_data, i)
		i += 1
