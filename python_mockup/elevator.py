DEFAULT_HEIGHT = 34
DEFAULT_FLOOR = 0
DEFAULT_DIRECTION = True #heading up from the ground floor
DEFAULT_USERS = {} 

class Elevator(object): 
    
    def __init__(self, direction=DEFAULT_DIRECTION, height=DEFAULT_HEIGHT,
                 floor=DEFAULT_FLOOR, users=DEFAULT_USERS):
        self.direction = direction
        self.height = height
        self.floor = floor
        self.users = users

    def __repr__(self):
        msg = "Direction: {direction:<2} Height: {height:<3} "\
              "Floor:{floor:<2} Users: {users}"
        return msg.format(direction=self.direction, height=self.height,
                          floor=self.floor, users=self.users)

    def moveFloor(self):
        usersToRemove = []
        increment = 1 if self.direction else -1
        self.floor += increment

        for userId, user in self.users.items():
            user.moveFloor()
            user.currentFloor = self.floor
            if user.hasReachedDestination():
                usersToRemove.append(userId)

        for userId in usersToRemove:
            self.users[userId].addBoardingDuration()
            del self.users[userId]

    def userEnters(self, user):
        user.addBoardingDuration()
        self.users[user.id] = user

    def hasUsersRiding(self):
        return len(self.users) == 0
