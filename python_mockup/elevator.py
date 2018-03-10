DEFAULT_HEIGHT = 34
DEFAULT_FLOOR = 0
UP = True
DOWN = False
DEFAULT_DIRECTION = UP 

class Elevator(object):
    
    def __init__(self, direction, height=DEFAULT_HEIGHT, floor=DEFAULT_FLOOR):
        self.direction = direction
        self.height = height
        self.floor = floor

    def __repr__(self):
        return "Direction: {0:<2} Height: {1:<3} Floor:{2}".format(self.direction,
                                                                   self.height,
                                                                   self.floor)
