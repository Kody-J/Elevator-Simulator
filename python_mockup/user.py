FLOOR_INTERVAL = 5
USER_BOARDING_INTERVAL = 10

class User(object):

    def __init__(self, name, currentFloor, targetFloor, orderPressed):
        self.name = name
        self.currentFloor = currentFloor 
        self.targetFloor = targetFloor
        self.direction = self.getDirection()
        self.duration = 0
        self.id = self.getUserId(orderPressed)

    def __repr__(self):
        msg = "Name: {name:<10} Current Floor: {current:<2} "\
              "Target Floor {target:<2} Direction: {direction:<4} "\
              "Duration: {duration}"
        return msg.format(name=self.name, current=self.currentFloor,
                          target=self.targetFloor, direction=self.direction,
                          duration=self.duration)
 
    def getDirection(self):
        return self.currentFloor < self.targetFloor

    def getUserId(self, order):
        return hash((self.name, self.targetFloor, order))

    def hasReachedDestination(self):
        return self.currentFloor == self.targetFloor

    def moveFloor(self):
        self.duration += FLOOR_INTERVAL

    def addBoardingDuration(self):
        self.duration += USER_BOARDING_INTERVAL
