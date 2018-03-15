#include "User.h"

const int FLOOR_INTERVAL = 5;
const int USER_BOARDING_INTERVAL = 10;

User::User() {
	name = "";
	currentFloor = 0;
	targetFloor = 0;
	direction = getDirection();
	duration = 0;
	id = "";
}

User::User(std::string n, int currentF, int targetF, int orderPassed) {
	name = n;
	currentFloor = currentF;
	targetFloor = targetF;
	direction = getDirection();
	duration = 0;
	id = getUserId(orderPassed);
}

std::string User::getName() { return name; };
int User::getCurrentFloor() { return currentFloor; };
int User::getTargetFloor() { return targetFloor; };
bool User::getDirection() {
	return currentFloor < targetFloor; // true = going up
}
std::string User::getUserId(int order) {
	// returns string of "Name TargetFloor Order"
	return name + " " + std::to_string(targetFloor) + " " + std::to_string(order);
}

void User::setName(int newName) { name = newName; };
void User::setCurrentFloor(int newFloor) { currentFloor = newFloor; };
void User::setTargetFloor(int newFloor) { targetFloor = newFloor; };

void User::moveFloor() {
	duration += FLOOR_INTERVAL;
}
void User::addBoardingDuration() {
	duration += USER_BOARDING_INTERVAL;
}
