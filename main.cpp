#include "User.h"
#include "Elevator.h"

#include <vector>
#include <queue>

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

// finish copying makeUsers
std::queue<User> makeUsers(int count = 10, int upperLimit = DEFAULT_HEIGHT);

// finish copying makeElevators
std::queue<Elevator> makeElevators(int count = 2, int height = DEFAULT_HEIGHT);

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

std::queue<User> makeUsers(int count = 10, int upperLimit = DEFAULT_HEIGHT) {
	std::queue<User> retval;
	
	return retval;
}

std::queue<Elevator> makeElevators(int count = 2, int height = DEFAULT_HEIGHT) {
	std::queue<Elevator> retval;

	return retval;
}
