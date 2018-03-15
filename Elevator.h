#pragma once

class Elevator {
private:
	int height;
	int floor;
	bool direction; // True = up
public:
	Elevator();
	Elevator(int h, int f, bool d);

	int getHeight();
	int getFloor();
	bool getDirection();

	void setHeight(int newHeight);
	void setFloor(int newFloor);
	void setDirection(bool newDir);
};