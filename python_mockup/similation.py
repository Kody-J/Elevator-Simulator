#!/usr/bin/env python

from util import makeUsers, makeElevators

INTERVAL = 10

def floorsApart(target, destination):
    return abs(target.floor - destination.floor)

def move(user, elevators):
    nearestElevator = elevators[0]
    nearestDifference = floorsApart(user, elevators[0])
    for elevator in elevators[1:]:
        difference = floorsApart(user, elevator)
        if difference < nearestDifference:
            nearestDifference = difference
            nearestElevator = elevator
        elif difference == nearestDifference:
            nearestDifference = difference
            nearestElevator = elevator
            break

    nearestElevator.floor = user.floor
    nearestElevator.direction = user.direction
    timeWaiting = nearestDifference * INTERVAL
    return timeWaiting

if __name__ == '__main__':
    elevators = makeElevators()
    users = makeUsers()
    while users:
        user = users.popleft()
        timeWaiting = move(user, elevators)
        #time waiting is calculated by number of floors moved * interval
        #current assumption seems like 10 seconds per floor. Seems like 
        #we have the freedom to create an arbitrary metric as such
        print (user, timeWaiting)
