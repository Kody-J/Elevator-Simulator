#pragma once

#include <string>

class User {
private:
	std::string name;
	int floor;
	bool direction;
public:
	User() {
		name = "";
		floor = 0;
		direction = true;
	}
	User(std::string n, int f, bool d) {
		name = n;
		floor = f;
		direction = d;
	}

	std::string getName() { return name; };
	int getFloor() { return floor; };
	bool getDirection() { return direction; };

	void setName(int newName) { name = newName; };
	void setFloor(int newFloor) { floor = newFloor; };
	void setDirection(bool newDir) { direction = newDir; };
};
