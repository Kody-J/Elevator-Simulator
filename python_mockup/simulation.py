#!/usr/bin/env python

from util import makeUsers, makeElevators
 
def getNearestElevator(floor, elevators):
    nearestDiff = abs(floor - elevators[0].floor)
    retval = (elevators[0], nearestDiff)
    if nearestDiff != 0:
        for elevator in elevators[1:]:
            difference = abs(floor - elevator.floor)
            if difference == 0:
                retval = (elevator, 0)
                break
            if difference < nearestDiff:
                nearestDiff = difference
                retval = (elevator, nearestDiff)

    return retval

def doRandomSimulation():
    elevators = makeElevators()
    users = makeUsers()
    usersRequestedElevator= []

    while users:
        user = users.popleft()
        usersRequestedElevator.append(user)
        elevator, distance = getNearestElevator(user.currentFloor, elevators)
        if distance != 0:
            elevator.userEnters(user)
            for _ in range(0, distance):
                elevator.moveFloor()

    for elevator in elevators:
        while elevator.hasUsersRiding():
            elevator.moveFloor()

    return [(user.name, user.duration) for user in usersRequestedElevator]
        
def printResults(results):
    for user, duration in results:
        print "{0:<10} {1}".format(user, duration)

if __name__ == '__main__':
    results = doRandomSimulation()
    printResults(results)
