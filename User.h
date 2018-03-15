#pragma once

#include <string>

class User {
private:
	std::string name;
	int currentFloor;
	int targetFloor;
	bool direction;
	int duration;
	std::string id;
public:
	User();
	User(std::string n, int currentF, int targetF, int orderPassed);

	std::string getName();
	int getCurrentFloor();
	int getTargetFloor();
	bool getDirection();
	std::string getUserId(int order);

	void setName(int newName);
	void setCurrentFloor(int newFloor);
	void setTargetFloor(int newFloor);
	
	void moveFloor();
	void addBoardingDuration();
};
