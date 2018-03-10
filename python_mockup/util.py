from user import User
from elevator import Elevator, DEFAULT_HEIGHT

from collections import deque
from random import randrange, choice

NAMES = ['Oliver', 'Jack', 'Harry', 'Jacob', 'Charlie', 'Thomas', 'George',
         'Oscar', 'James', 'William', 'Amelia', 'Olivia', 'Isla', 'Emily',
         'Poppy', 'Ava', 'Isabella', 'Jessica', 'Lily', 'Sophie']
UP = True
DOWN = False
DIRECTIONS = (UP, DOWN)

def makeUsers(count=10, upperLimit=DEFAULT_HEIGHT):
    """ returns a deque of users, defaults to 10"""
    retval = deque()
    for _ in xrange(0, count):
        name = choice(NAMES)
        #TODO set boundries correctly, allowing floor 0 and floor n 
        floor = randrange(1, upperLimit)
        direction = choice(DIRECTIONS)
        retval.append(User(name, floor, direction))
    return retval

def makeElevators(count=2, height=DEFAULT_HEIGHT):
    retval = list()
    floors = range(0, height)
    for _ in xrange(0, count):
        direction = choice(DIRECTIONS)
        floor = choice(floors)
        retval.append(Elevator(direction=direction, floor=floor)) 
    return retval
