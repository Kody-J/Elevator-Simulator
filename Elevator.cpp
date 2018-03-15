#include "Elevator.h"

const int DEFAULT_HEIGHT = 34;
const int DEFAULT_FLOOR = 0;
const int DEFAULT_DIRECTION = true; // heading up

Elevator::Elevator() {
	height = DEFAULT_HEIGHT;
	floor = DEFAULT_FLOOR;
	direction = DEFAULT_DIRECTION;
}
Elevator::Elevator(int h, int f, bool d) {
	height = h;
	floor = f;
	direction = d;
}

int Elevator::getHeight() { return height; };
int Elevator::getFloor() { return floor; };
bool Elevator::getDirection() { return direction; };

void Elevator::setHeight(int newHeight) { height = newHeight; };
void Elevator::setFloor(int newFloor) { floor = newFloor; };
void Elevator::setDirection(bool newDir) { direction = newDir; };
