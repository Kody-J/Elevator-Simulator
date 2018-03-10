def move(user, 

class Move(object):


    def __init__(self, users=None, elevators=None):
        self.users = users
        self.elevators = elevators 

    def run(self):
        #popleft user from deque 
        #find nearest elevator
        #calculate difference in floors
        #waiting (in seconds) = floor difference * 10
        #move elevator to that floor
        #add user and waiting time to return value
        pass
        
