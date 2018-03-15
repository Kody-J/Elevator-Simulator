#include "User.h"
#include "Elevator.h"

#include <vector>
#include <queue>
#include <random>
#include <iostream>

const int INTERVAL = 10;
const int DEFAULT_HEIGHT = 34;
const int DEFAULT_FLOOR = 0;
const int DEFAULT_DIRECTION = true; // heading up

bool UP = true;
bool DOWN = false;
bool DIRECTIONS[2] = { UP, DOWN };
std::string NAMES[20] = { "Oliver", "Jack", "Harry", "Jacob", "Charlie", "Thomas", "George", "Oscar", "James", "William", "Amelia", "Olivia", "Isla", "Emily", "Poppy", "Ava", "Isabella", "Jessica", "Lily", "Sophie" };


int floorsApart(User target, Elevator destination);
int move(User u, std::vector<Elevator> elevators);

std::vector<User> makeUsers(int count = 10, int upperLimit = DEFAULT_HEIGHT);

std::vector<Elevator> makeElevators(int count = 2, int height = DEFAULT_HEIGHT);

void main() {
	// simulation.py
}

int floorsApart(User target, Elevator destination) {
	return abs(target.getFloor() - destination.getFloor());
}

int move(User u, std::vector<Elevator> elevators) {
	Elevator nearestElevator = elevators[0];
	int nearestDifference = floorsApart(u, elevators[0]);
	for (int i = 0; i < elevators.size(); i++) {
		int difference = floorsApart(u, elevators[i]);
		if (difference < nearestDifference) {
			nearestDifference = difference;
			nearestElevator = elevators[i];
		}
		else if (difference == nearestDifference) {
			nearestDifference = difference;
			nearestElevator = elevators[i];
			break;
		}
	}
	nearestElevator.setFloor(u.getFloor());
	nearestElevator.setDirection(u.getDirection());
	int timeWaiting = nearestDifference * INTERVAL;
	return timeWaiting;
}

std::vector<User> makeUsers(int count = 10, int upperLimit = DEFAULT_HEIGHT) {
	std::vector<User> retval;

	for (int order = 0; order < count; order++) {
		std::string name = NAMES[rand() % 19]; // random name choice (0-19)
		int currentFloor = rand() % (upperLimit / 2); // random number from 0 -> upperLimit
		int targetFloor = rand() % upperLimit; // random number from 0 -> upperLimit
		retval[order] = User(name, currentFloor, targetFloor, order);
	}

	return retval;
}

std::vector<Elevator> makeElevators(int count = 2, int height = DEFAULT_HEIGHT) {
	std::vector<Elevator> retval;

	for (int j = 0; j < count; j++) {
		bool direction = DIRECTIONS[rand() % 1]; // random dir choice (0,1)
		int floor = rand() % height; // random from 0 -> height
		retval[j] = Elevator(direction, floor);
	}

	return retval;
}
