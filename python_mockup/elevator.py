DEFAULT_HEIGHT = 34
DEFAULT_FLOOR = 0
DEFAULT_DIRECTION = True #heading up from the ground floor

class Elevator(object):
    
    def __init__(self, direction=DEFAULT_DIRECTION, height=DEFAULT_HEIGHT, floor=DEFAULT_FLOOR):
        self.direction = direction
        self.height = height
        self.floor = floor

    def __repr__(self):
        return "Direction: {0:<2} Height: {1:<3} Floor:{2}".format(self.direction,
                                                                   self.height,
                                                                   self.floor)
