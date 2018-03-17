#include <vector>
#include <map>

using namespace std;

class Elevator : private User
{

private:

	int height;
	map<string, User> users;
	int floor;
	bool direction; // True = up

public:
	Elevator();
	Elevator(int h, int f, bool d);

	int getHeight();
	int getFloor();

	bool getDirrection();
	bool hasUsersRiding();
	
	void setHeight(int newHeight);
	void setFloor(int newFloor);
	void setDirection(bool newDir);
	void moveFloor();
	void userEnters(User usr);
	
	~Elevator();
};

