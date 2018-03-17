#include "stdafx.h"
#include "Elevator.h"


const int DEFAULT_HEIGHT = 34;
const int DEFAULT_FLOOR = 0;
const int DEFAULT_DIRECTION = true; // heading up

Elevator::Elevator(){
	height = DEFAULT_HEIGHT;
	floor = DEFAULT_FLOOR;
	direction = DEFAULT_DIRECTION;
}
Elevator::Elevator(int h, int f, bool d) {
	height = h;
	floor = f;
	direction = d;
}
int Elevator::getHeight(){return height;}
int Elevator::getFloor(){return floor;}
bool Elevator::getDirrection(){return direction;}
bool Elevator::hasUsersRiding(){return users.size() == 0;}
void Elevator::moveFloor(){
	vector<string> usersToRemove;
	int increment;
	if (direction)
		increment = 1;
	else
		increment = -1;
	floor += increment;
	for (map<string, User>::iterator itr = users.begin(); itr != users.end(); itr++)
	{
		itr->second.moveFloor();
		itr->second.setCurrentFloor(floor);
		if (itr->second.hasReachedDestination())
		{
			usersToRemove.push_back(itr->second.getUserId());
		}
	}
	for (int i = 0; i < usersToRemove.size(); i++){
		users[usersToRemove[i]].addBoardingDuration();
		users.erase(usersToRemove[i]);
	}
}
void Elevator::userEnters(User usr){
	usr.addBoardingDuration();
	users[usr.getUserId()] = usr;
}
void Elevator::setHeight(int newHeight){height = newHeight;}
void Elevator::setFloor(int newFloor){floor = newFloor;}
void Elevator::setDirection(bool newDir){direction = newDir;}
Elevator::~Elevator(){}
