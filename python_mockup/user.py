class User(object):

    def __init__(self, name, floor, direction):
        self.name = name
        self.floor = floor
        self.direction = direction

    def __repr__(self):
        return "Name: {0:<10} Floor: {1:<2} Direction {2}".format(self.name,
                                                                  self.floor,
                                                                  self.direction)
