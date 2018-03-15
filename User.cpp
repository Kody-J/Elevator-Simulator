#include "User.h"

User::User() {
	name = "";
	floor = 0;
	direction = true;
}
User::User(std::string n, int f, bool d) {
	name = n;
	floor = f;
	direction = d;
}

std::string User::getName() { return name; };
int User::getFloor() { return floor; };
bool User::getDirection() { return direction; };

void User::setName(int newName) { name = newName; };
void User::setFloor(int newFloor) { floor = newFloor; };
void User::setDirection(bool newDir) { direction = newDir; };
